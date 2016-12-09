#!/usr/bin/env python 
# -*- coding: UTF-8 -*-
import pika  
  
#channel.queue_declare(queue='Hello', auto_delete=True)  
connection = pika.BlockingConnection(pika.ConnectionParameters(
        host='localhost'))


channel = connection.channel()

channel.queue_declare(queue='hello', 
											auto_delete=False)

def callback(ch, method, properties, body):
    print(" [x] Received %r" % body)

channel.basic_consume(callback,
                      queue='hello',
                      no_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()