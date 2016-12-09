#!/usr/bin/python 
# -*- coding: UTF-8 -*-
import pika  

connection = pika.BlockingConnection(pika.ConnectionParameters(
        host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello-queue', 
											auto_delete=True)

channel.basic_publish(exchange='hello-exchange',
                      routing_key='hola',
                      body='Hello World!')
print(" [x] Sent 'Hello World!'")
connection.close()