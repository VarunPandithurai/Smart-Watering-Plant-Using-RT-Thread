/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Date           Author               Notes
 * 2020-12-25     Varun Pandithurai    first version
 */

// Including Required Libraries and Preprocessors
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "tc_comm.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#define LED0_PIN               GET_PIN(A, 5)
#define LED1_PIN               GET_PIN(A, 6)
#define Sensor               GET_PIN(C, 0)
#define Pump                GET_PIN(A, 10)
#include <rtdbg.h>
// Creating Structures for Threads
struct rt_thread thread1;
struct rt_thread thread2;
struct rt_thread thread3;
static char thread1_stack[THREAD_STACK_SIZE];
static char thread2_stack[THREAD_STACK_SIZE];
static char thread3_stack[THREAD_STACK_SIZE];
static rt_uint32_t data = 1;
rt_uint32_t val;

// Thread defenitions

static void thread3_entry(void* parameter)
{
    rt_pin_mode(Sensor, PIN_MODE_INPUT);
    while (1)
    {   val=rt_pin_read(Sensor);
        if(val>0)
        {
            data=1;
        }
        else
        {
            data=2;
        }
    }

}


static void thread1_entry(void* parameter)
{
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(Pump, PIN_MODE_OUTPUT);
    while (1)
    {
        if(data==1)
        {
            rt_pin_write(LED0_PIN, PIN_HIGH);
            rt_thread_mdelay(1);
            rt_pin_write(Pump, PIN_LOW);
            rt_thread_mdelay(10);
        }
        else
        {
            rt_pin_write(LED0_PIN, PIN_LOW);
            rt_thread_mdelay(1);
            rt_pin_write(Pump, PIN_HIGH);
            rt_thread_mdelay(1);
        }
    }

}

static void thread2_entry(void* parameter)
{
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
            if(data==2)
            {
                rt_pin_write(LED1_PIN, PIN_HIGH);
                rt_thread_mdelay(1);

            }
             else
            {
                 rt_pin_write(LED1_PIN, PIN_LOW);
                 rt_thread_mdelay(1);

            }
    }
}

// Setting thread Priority

#ifdef RT_USING_TC
static void _tc_cleanup()
{
    /* lock scheduler */
    rt_enter_critical();

    if (thread1.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread1);
    if (thread2.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread2);
    if (thread3.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread3);

    /* unlock scheduler */
    rt_exit_critical();
}
int _tc_thread_priority()
{
    /* set tc cleanup */
    tc_cleanup(_tc_cleanup);


    return RT_TICK_PER_SECOND;
}
FINSH_FUNCTION_EXPORT(_tc_thread_priority, a priority thread test);
#endif




int main(void)
{
    // Initializing and starting the threads
    rt_thread_init(&thread1,"t1",thread1_entry, RT_NULL,&thread1_stack[0], sizeof(thread1_stack),THREAD_PRIORITY - 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread1);

    rt_thread_init(&thread2,"t2",thread2_entry, RT_NULL,&thread2_stack[0], sizeof(thread2_stack),THREAD_PRIORITY + 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread2);

    rt_thread_init(&thread3,"t2",thread3_entry, RT_NULL,&thread3_stack[0], sizeof(thread3_stack),THREAD_PRIORITY + 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread3);

    return 0;
}
