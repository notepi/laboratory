#!/usr/bin/env python 
# -*- coding: UTF-8 -*-
import pika  
import logging
logging.basicConfig()

credentials = pika.PlainCredentials("guest", "guest")
conn_params = pika.ConnectionParameters("localhost",
																				credentials = credentials)
conn_broker = pika.BlockingConnection(conn_params)
channel = conn_broker.channel()

channel.exchange_declare(exchange='hello-exchange')

channel.queue_declare(queue="hello-queue", auto_delete=True)

channel.queue_bind(queue="hello-queue",
										exchange="hello-exchange",
										routing_key="hola")
def msg_consumer(channel, method, header, body):
		channel.basic_ack(delivery_tag=method.delivery_tag)
		if body == "quit":
			channel.basic_cancel(consumer_tag="hello-consumer")
			channel.stop_consuming()
		else:
			print body
		return
channel.basic_consume(msg_consumer,
											queue="hello-queue",
											consumer_tag="hello-consumer")	
print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming ()