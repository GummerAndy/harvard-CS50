#include <cs50.h>
#include <stdio.h>

// PROMPT USER FOR INPUT
long getCreditCardNumber(long creditCardNumber);
long getNumDigitsInCreditCard(long creditCardNumberCount, int count);
long calculateCheckSum(long totalSumOfAddedDigits, long totalSumOfMultipliedDigits, int finalSum , long tempCreditCardNumber, int count);
long validateCard(int finalSum, long creditCardNumber, int count);


int main(void)
{
    long creditCardNumber = 0;

    creditCardNumber = getCreditCardNumber(creditCardNumber);

    //Calculate amount of digits in creditCardNumber
    long creditCardNumberCount = creditCardNumber;
    int count = 0;
    
    count = getNumDigitsInCreditCard(creditCardNumberCount, count);


    // CALCULATING THE CHECKSUM
    // Variables for calculations
    long totalSumOfAddedDigits = 0;
    long totalSumOfMultipliedDigits = 0;
    int finalSum = 0;
    long tempCreditCardNumber = creditCardNumber;
    
    //Calculate checksum when the creditcardnumber is even:
    if (count % 2 == 0) {
        finalSum =  calculateCheckSum(totalSumOfAddedDigits, totalSumOfMultipliedDigits, finalSum, tempCreditCardNumber, count);
    }
    //Calculate checksum when creditCardNumber is odd
    else {    
        finalSum =  calculateCheckSum(totalSumOfAddedDigits, totalSumOfMultipliedDigits, finalSum, tempCreditCardNumber, count);
    }

    //CHECK FOR START LENGTH AND STARTING DIGITS AND PRINT OUTPUT
    validateCard(finalSum, creditCardNumber, count);
}

long getCreditCardNumber(long creditCardNumber){
    do 
    {
        creditCardNumber = get_long("Credit card number:\n");
    }
    while(creditCardNumber <  1);

    return creditCardNumber;
};

long getNumDigitsInCreditCard(long creditCardNumberCount, int count){;
    do
    {
        /* Increment digit count */
        count++;

        /* Remove last digit of 'num' */
        creditCardNumberCount /= 10;
    } 
    while(creditCardNumberCount != 0);

    return count;
};

long calculateCheckSum(long totalSumOfAddedDigits, long totalSumOfMultipliedDigits, int finalSum, long tempCreditCardNumber, int count){
    for (int i = 0; i < count; i++){
        long remainderTempCreditCardNumber =  tempCreditCardNumber % 10;

        tempCreditCardNumber /= 10;

        // These numbers need to be multiplied
        if(i % 2 != 0){
            if(remainderTempCreditCardNumber < 5) {
                totalSumOfMultipliedDigits += remainderTempCreditCardNumber*2;
            }
            else {
                int firstDigit = (remainderTempCreditCardNumber * 2) / 10;
                int secondDigit = (remainderTempCreditCardNumber * 2) % 10;
                totalSumOfMultipliedDigits += firstDigit + secondDigit;
            }
        }
        // These numbers need to be added
        else {
            totalSumOfAddedDigits += remainderTempCreditCardNumber;
        }
};
        return finalSum =  totalSumOfMultipliedDigits + totalSumOfAddedDigits;
};

long validateCard(int finalSum, long creditCardNumber, int count){
    if(count >= 13 && count <= 16){
        long multiplier = 1;
        
        for(int i = 0; i < count; i++){
            multiplier *= 10;
        }

        long firstTwoDigits = creditCardNumber / (multiplier / 100);
        long firstDigit = creditCardNumber / (multiplier / 10);

        if(firstDigit == 4 && (count >= 13 || count <= 16 )) {
            if(finalSum % 10 == 0) {
                return printf("VISA\n");
            }
            else {
                return printf("INVALID\n");
            }
        }

        else if((firstTwoDigits == 34 || firstTwoDigits ==37) && count == 15) {
            if(finalSum % 10 == 0) {
                return printf("AMEX\n");
            }
            else {
                return printf("INVALID\n");
            }
        }
        
        else if((firstTwoDigits >= 51 && firstTwoDigits <=55) && count == 16) {
            if(finalSum % 10 == 0) {
            return printf("MASTERCARD\n");
            }
            else {
                return printf("INVALID\n");
            }
        }
        else {
            return printf("INVALID\n");
        }
    } else {
        return printf("INVALID\n");
    }
 }
