/*
 * Copyright (c) 2022, Technoculture Research
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/__assert.h>
#include <sys/printk.h>
#include <zephyr.h>

#define STACKSIZE 1024

K_FIFO_DEFINE(message_buffer);

struct data_item {
  void *fifo_reserved;
  int num;
};

void producer_thread(void) {
  while (1) {
    struct data_item *tx_data = k_malloc(sizeof(struct data_item));
    __ASSERT_NO_MSG(tx_data != 0);

    tx_data->num = 3;

    k_fifo_put(&message_buffer, tx_data);
  }
}

void consumer_thread(void) {
  while (1) {
    struct data_item *rx_data;
    rx_data = k_fifo_get(&message_buffer, K_FOREVER);
    printk("Received value = %d\n", rx_data->num);
    k_free(rx_data);
  }
}

K_THREAD_DEFINE(producer, STACKSIZE, producer_thread, NULL, NULL, NULL,
                K_LOWEST_APPLICATION_THREAD_PRIO, 0, 0);
K_THREAD_DEFINE(consumer, STACKSIZE, consumer_thread, NULL, NULL, NULL,
                K_LOWEST_APPLICATION_THREAD_PRIO, 0, 0);

void main(void) {
  printk("Hello World! %s\n", CONFIG_BOARD);

  k_thread_start(producer);
  k_thread_start(consumer);

  k_fifo_init(&message_buffer);
}
