# Compile everything first
g++ gen.cpp -o gen
g++ sol.cpp -o sol
g++ auth.cpp -o auth
g++ val.cpp -o val

# The Loop
for ((i=1;; i++)); do
    # 1. Generate
    ./gen $i > input.txt
    
    # 2. Run Both
    ./sol < input.txt > out_my.txt
    ./auth < input.txt > out_auth.txt
    
    # 3. Validate Yours (Silent check)
    ./val input.txt out_my.txt > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        printf "❌ Test %d: Your solution produced Invalid Output!\n" "$i"
        break
    fi

    # 4. Extract k
    read k_my < out_my.txt
    read k_auth < out_auth.txt

    # 5. Compare using printf (Safe for Mac)
    if [ "$k_my" -gt "$k_auth" ]; then
        # Yellow Text for "Me", Green for "Auth"
        printf "Test %d: \033[33mMe=%d\033[0m vs \033[32mAuth=%d\033[0m (Worse)\n" "$i" "$k_my" "$k_auth"
    
    elif [ "$k_my" -lt "$k_auth" ]; then
        # Cyan Text for "Me" (Better)
        printf "Test %d: \033[36mMe=%d\033[0m vs \033[32mAuth=%d\033[0m (Better!)\n" "$i" "$k_my" "$k_auth"
    
    else
        # Normal Text
        printf "Test %d: Me=%d vs Auth=%d (Same)\n" "$i" "$k_my" "$k_auth"
    fi
done