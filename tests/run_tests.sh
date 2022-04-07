echo ""
echo "================================================================"
echo "Running unit tests (code-based test cases)..."
echo "================================================================"
echo ""

make

./sim bimodal 6 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_bimodal_1.txt > /dev/null
diff_val=$?


./sim bimodal 12 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_bimodal_2.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim bimodal 4 jpeg_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_bimodal_3.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim gshare 9 3 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_gshare_1.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim gshare 14 8 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_gshare_2.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim gshare 11 5 jpeg_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_gshare_3.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim hybrid 8 14 10 5 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_hybrid_1.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim smith 3 gcc_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_smith_1.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim smith 1 jpeg_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_smith_2.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi


./sim smith 4 perl_trace.txt > res.txt
diff -i -w res.txt ./data/validation_runs/val_smith_3.txt > /dev/null
diff_val=$?
if  [[ $diff_val != 0 ]]; then
        echo "fail (output mismatch)"
else
        echo "PASS!"
fi

