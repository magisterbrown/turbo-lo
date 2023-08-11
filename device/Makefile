CONFIG_MODULE_SIG=n
obj-m += final_dev.o

all:
	make -C /lib/modules/6.4.1-arch2-1/build M=$(PWD)
clean:
	make -C /lib/modules/6.4.1-arch2-1/build M=$(PWD) clean
