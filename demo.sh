echo "Press q to quit the current demo and proceed to the next one."
echo "Press s to pause the scene."
CMD=../bin/birdFountain
cd demo;
$CMD < demo/demo1.in > /dev/null
$CMD < demo/demo2.in > /dev/null 
$CMD < demo/demo3.in > /dev/null
$CMD < demo/demo4.in > /dev/null
$CMD < demo/demo6.in > /dev/null
$CMD < demo/demo7.in > /dev/null
$CMD < demo/demo8.in > /dev/null
$CMD < demo/demo9.in > /dev/null
$CMD < demo/demot.in > /dev/null
$CMD < demo/demo10.in > /dev/null
$CMD < demo/demof.in > /dev/null
cd ..


