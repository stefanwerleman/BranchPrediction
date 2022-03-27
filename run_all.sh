make

if [ ! -z "$1" ]
then
    if [ $1 == 1 ]
    then
    echo "======================VAL_BIMODAL_1======================"
    ./sim bimodal 6 gcc_trace.txt

    elif [ $1 == 2 ]
    then

    echo "======================VAL_BIMODAL_2======================"
    ./sim bimodal 12 gcc_trace.txt

    elif [ $1 == 3 ]
    then

    echo "======================VAL_BIMODAL_3======================"
    ./sim bimodal 4 jpeg_trace.txt

    elif [ $1 == 4 ]
    then

    echo "======================VAL_GSHARE_1======================="
    ./sim gshare 9 3 gcc_trace.txt

    elif [ $1 == 5 ]
    then

    echo "======================VAL_GSHARE_2======================="
    ./sim gshare 14 8 gcc_trace.txt

    elif [ $1 == 5 ]
    then

    echo "======================VAL_GSHARE_3======================="
    ./sim gshare 11 5 jpeg_trace.txt

    elif [ $1 == 6 ]
    then

    echo "======================VAL_HYBRID_1======================="
    ./sim hybrid 8 14 10 5 gcc_trace.txt

    elif [ $1 == 7 ]
    then

    echo "======================VAL_SMITH_1========================"
    ./sim smith 3 gcc_trace.txt

    elif [ $1 == 8 ]
    then

    echo "======================VAL_SMITH_2========================"
    ./sim smith 1 jpeg_trace.txt

    elif [ $1 == 9 ]
    then

    echo "======================VAL_SMITH_3========================"
    ./sim smith 4 perl_trace.txt
    fi

else

echo "======================VAL_BIMODAL_1======================"
./sim bimodal 6 gcc_trace.txt

echo "======================VAL_BIMODAL_2======================"
./sim bimodal 12 gcc_trace.txt

echo "======================VAL_BIMODAL_3======================"
./sim bimodal 4 jpeg_trace.txt

echo "======================VAL_GSHARE_1======================="
./sim gshare 9 3 gcc_trace.txt

echo "======================VAL_GSHARE_2======================="
./sim gshare 14 8 gcc_trace.txt

echo "======================VAL_GSHARE_3======================="
./sim gshare 11 5 jpeg_trace.txt

echo "======================VAL_HYBRID_1======================="
./sim hybrid 8 14 10 5 gcc_trace.txt

echo "======================VAL_SMITH_1========================"
./sim smith 3 gcc_trace.txt

echo "======================VAL_SMITH_2========================"
./sim smith 1 jpeg_trace.txt

echo "======================VAL_SMITH_3========================"
./sim smith 4 perl_trace.txt
fi