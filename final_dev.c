// Standart module import
#include <linux/module.h>

// Net device imports
#include <linux/netdevice.h>
#include <linux/etherdevice.h>


static int final_init(struct net_device *dev) {
	return 0;
}

static netdev_tx_t final_xmit(struct sk_buff *skb, struct net_device *dev) {
	kfree_skb(skb);

	printk("Dropped frame");
	
	return NETDEV_TX_OK;
}

static const struct net_device_ops final_ops = {
	.ndo_init = final_init, 
	.ndo_set_mac_address = eth_mac_addr,
	.ndo_start_xmit = final_xmit,
};

static void final_setup(struct net_device *dev) {
	dev->netdev_ops = &final_ops;
}

struct net_device *dev;
int __init start(void) {

	dev = alloc_netdev(0, "turbo_lo", NET_NAME_PREDICTABLE, final_setup);
	register_netdev(dev);
	
	return 0;
}

void __exit stop(void) {
	unregister_netdev(dev);
	free_netdev(dev);
}

module_init(start);
module_exit(stop);

MODULE_LICENSE("GPL");
