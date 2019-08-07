# FOTA 
Formware over the air transmission using easyQ.



### Build

Follow [this](https://github.com/easyqiot/esp-env) instruction 
to setup your environment.


```bash
source esp-env/nonos/activate.sh

cd esp-env/sdk/
git clone git@github.com:easyqiot/fota.git
cd fota 
bash gen_misc.sh
```

Or:

```bash
make clean
make assets
make flash_map6user1 

```
