#include <linux/module.h>
#include <linux/init.h>
#include <linux/thermal.h>
#include <linux/utsname.h>

struct thermal_zone_device *tz;
int temp;
int ret;

static int __init my_init(void) {
	tz = thermal_zone_get_zone_by_name("cpu-thermal");
	if (IS_ERR(tz))
	{
        	pr_err("Thermal-Zone nicht gefunden\n");
        	return PTR_ERR(tz);
        }
	printk("%i", tz);
	ret = thermal_zone_get_temp(tz, &temp);
	if (ret == 0)
	       {
			 printk("         ------=---                      ");
			 printk("       ----==/---=---   -                ");
			pr_info("  -   /-==/----=---O----                  OS: %s\n", utsname()->sysname);
    			pr_info("  -- /-----=/--- V V V V                  CPU Temperatur: ~%d C°\n", temp / 1000);
			pr_info("  ----=---=/------A A A                   Hostname: %s\n", utsname()->nodename);
			pr_info("  -     -------=----                      Kernel Version: %s\n", utsname()->release);
    	} else {
		pr_err("Fehler beim Lesen der Temperatur: %d\n :(", ret);
               }

	return 0;
}

static void __exit my_exit(void)
{
    printk(KERN_INFO "Modul entladen1\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vincent");
MODULE_DESCRIPTION("CPU Temperaturleser");
