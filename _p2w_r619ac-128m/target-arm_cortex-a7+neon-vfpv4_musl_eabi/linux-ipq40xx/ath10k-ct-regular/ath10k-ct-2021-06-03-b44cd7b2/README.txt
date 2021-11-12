This is a copy of the drivers/net/wireless/ath/ath10k tree from
the Candela-Technologies (CT) 4.7, 4.9, and 4.13 kernels.

This package may be useful for people trying to use CT ath10k
firmware on LEDE/OpenWRT, or other custom-built kernels.

The ath10k driver has a lot of patches, most of which are to enable it to
work more effectively with the ath10k CT firmware:

http://www.candelatech.com/ath10k.php

To compile with some help:
./build_me.sh

To compile manually:
cd ath10k
cp make_all make_all.mine
chmod a+x make_all.mine
# Edit make_all.mine to point to your compiled kernel
# Copy ath/*.h files into ../
# This header file stuff is not obvious, sorry..but it helps us compile
# properly on LEDE/OpenWRT backports infrastructure.
./make_all.mine


For full kernel source that these drivers came from, see:

http://dmz2.candelatech.com/?p=linux-4.7.dev.y/.git;a=summary
git clone git://dmz2.candelatech.com/linux-4.7.dev.y

http://dmz2.candelatech.com/?p=linux-4.4.dev.y/.git;a=summary
git clone git://dmz2.candelatech.com/linux-4.4.dev.y

Please send bug reports to:  greearb@candelatech.com
