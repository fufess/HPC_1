NUM_BLOCK = {60}
NUM_THREAD = {16, 32}

lb = {#NUM_BLOCK[@]}
lt = {#NUM_THREAD[@]}

for ((i=0; i<lb; i++))
do
	nb = NUM_BLOCK[i]
	for ((j=0; j<lt; j++))
	do
		nt = NUM_THREAD[j]
		$ cpi_test nb nt
		cpi_test
		nb
		nt
		$
	done
done
