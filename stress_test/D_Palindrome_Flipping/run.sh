for ((i=1; ; i++)); do
    # 1. Generate test case (pass 'i' as seed)
    ./gen $i > input.txt
    
    # 2. Run your solution
    ./sol < input.txt > output.txt
    
    # 3. Validate
    # (Capture validator output to see error messages if it fails)
    ./val input.txt output.txt > val_log.txt
    
    # 4. Check exit code (0 = success, anything else = fail)
    if [ $? -ne 0 ]; then
        echo "❌ FAILED on Test #$i"
        echo "See input.txt and output.txt for details."
        cat val_log.txt # Show why it failed
        break
    fi
    
    echo "✅ Passed Test #$i"
done