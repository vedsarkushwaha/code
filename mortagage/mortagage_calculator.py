LoanAmount = 335000
LoanInterestRate = 4.25
NumberOfYears = 30
MonthlyInstallment = 1648

FixedDepositAmountInDollars = 2000
DollarToRupees = 70
FixedDepositInterestRate = 7

def interest(principal, rateOfInterest, numberOfTerms=1):
	return (principal * rateOfInterest * numberOfTerms)/100

def loanCalculator():
	remainingLoanAmount = LoanAmount
	remainingLoanAmount_2000 = LoanAmount

	principalAndInterestList = []
	principalAndInterestList_2000 = []
	interestDiffList = []
	cummInterestDiff = 0
	for i in xrange(1,12*30+1):
		temp = interest(remainingLoanAmount, LoanInterestRate/12)
		remainingLoanAmount = remainingLoanAmount - (MonthlyInstallment - temp)
		principalAndInterest = ((MonthlyInstallment - temp), temp)
		principalAndInterestList.append(principalAndInterest)

		if(remainingLoanAmount_2000 > 0):
			temp_2000 = interest(remainingLoanAmount_2000, LoanInterestRate/12)
			remainingLoanAmount_2000 = remainingLoanAmount_2000 - (MonthlyInstallment - temp_2000) - 2000
			principalAndInterest_2000 = ((MonthlyInstallment - temp_2000), temp_2000)
			principalAndInterestList_2000.append(principalAndInterest_2000)
		else:
			temp_2000 = 0

		interestDiffList.append(temp - temp_2000)

		cummInterestDiff = cummInterestDiff + temp - temp_2000

		print temp, temp_2000, temp - temp_2000, cummInterestDiff

	totalInterest = 0
	for i in principalAndInterestList:
		totalInterest = totalInterest + i[1]
	# print totalInterest

	totalInterest = 0
	for i in principalAndInterestList_2000:
		totalInterest = totalInterest + i[1]
	# print totalInterest

def fixedDepositCalculator():
	remainingLoanAmount = LoanAmount
	remainingLoanAmount_2000 = LoanAmount

	principalAndInterestList = []
	principalAndInterestList_2000 = []
	interestDiffList = []
	cummInterestDiffList = []

	fdList = []
	# after this amount, I'll get
	returnDuration = 24
	# iterate over 30 years
	for i in xrange(1, 30*12+1):

		# Loan calculation
		temp = interest(remainingLoanAmount, LoanInterestRate/12)
		remainingLoanAmount = remainingLoanAmount - (MonthlyInstallment - temp)
		principalAndInterest = ((MonthlyInstallment - temp), temp)
		principalAndInterestList.append(principalAndInterest)

		if(remainingLoanAmount_2000 > 0):
			temp_2000 = interest(remainingLoanAmount_2000, LoanInterestRate/12)
			remainingLoanAmount_2000 = remainingLoanAmount_2000 - (MonthlyInstallment - temp_2000) - 2000
			principalAndInterest_2000 = ((MonthlyInstallment - temp_2000), temp_2000)
			principalAndInterestList_2000.append(principalAndInterest_2000)
		else:
			temp_2000 = 0

		interestDiffList.append(temp - temp_2000)

		cummInterestDiffList.append(temp - temp_2000)

		# FD calculation
		# amountInINR = 350000
		amountInINR = FixedDepositAmountInDollars * DollarToRupees
		
		# add new FD
		fdList.append(amountInINR)

		# calculate new FD values every quarter
		for j in range(i-3, -1, -3):
			fdList[j] = fdList[j] + interest(fdList[j], FixedDepositInterestRate/4)

	# Loan Calculation
	totalInterest = 0
	for i in principalAndInterestList:
		totalInterest = totalInterest + i[1]
	print totalInterest

	# FD Calculation
	totalInterest = 0
	for i in fdList:
		totalInterest = totalInterest + (i - amountInINR)
	print totalInterest/70

if __name__=="__main__":
	# loanCalculator()
	fixedDepositCalculator()