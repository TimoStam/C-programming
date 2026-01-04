multiply:
	MOVS.N R2, #0
	MOVS.N R3, R1
wait:
	SUBS.N R3, #1
	BMI.N end
	ADDS.N R2, R2, R0
	B.N wait
end:
	MOVS.N R0, R2
	BX.N LR