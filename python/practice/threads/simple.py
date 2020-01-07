import os
import logging
import threading
import time


# https://webdevblog.ru/vvedenie-v-potoki-v-python/
def thread_function(name):
    logging.info("Thread %s: starting", name)
    time.sleep(30)
    logging.info("Thread %s: finishing", name)


if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    logging.info("Pid     : {0}".format(os.getpid()))
    logging.info("Main    : before creating thread")

    x = threading.Thread(target=thread_function, args=(1,))
    logging.info("Main    : before running thread")
    x.start()

    logging.info("Main    : wait for the thread to finish")

    # Если не будет join, главный поток отработает до конца
    # и потом все равно будет висеть в ожидании завершения дочернего
    x.join()

    logging.info("Main    : all done")
