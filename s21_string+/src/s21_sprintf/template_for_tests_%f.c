// Testing %f with flags to write tests that would cover all I can cover for Mike
// -340282346638528859811704183484516925440.000000 to 340282346638528859811704183484516925440.000000

/*
+ 1. Write plan of testing %f by itself, with sign, with width, with precision
+ 2. Test regular number output without any flags - min value, max, average 
+ 3. Test how width behaves in %f - Min, average, max
+    Right-justify
+    Left-justify
+ 4. Test how precision behavess in %f - Min, average, max with different amount of digits after the dot
+ 5. Test how sign behaves with different values - negative, zero, positive, max
+ 6. Test with sign and width
+ 7. Test with sign and precision
+ 8. Test with width (left and right-justify) and precision
9. Test with sign, width and precision
*/


#include <stdio.h>

int main() {
    char buffer[1000] = {'f'};

    // !!! Start of the tests with no flags
    // Regular value test with no precision set
    sprintf(buffer, "[#1: %f]", 1234567.123456);
    puts(buffer);
    // Value after the decimal point that is bigger than defaul precision of 6, test with no precision set
    sprintf(buffer, "[#2: %f]", 1234567.123456789);
    puts(buffer);
    // Value after the decimal point that is less than defaul precision of 6, test with no precision set
    sprintf(buffer, "[#3: %f]", 1234567.123);
    puts(buffer);
    // No value after the decimal point, test with no precision set
    sprintf(buffer, "[#4: %f]", 1234567.);
    puts(buffer);
    // Zero value after the decimal point, test with no precision set
    sprintf(buffer, "[#5: %f]", 1234567.0);
    puts(buffer);
    // Maximum value, test with no precision set
    sprintf(buffer, "[#6: %f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than maximum value after the decimal point, test with no precision set
    sprintf(buffer, "[#7: %f]", 340282346638528859811704183484516925440.123456);
    puts(buffer);
    // More than maximum value, 50 digits after the decimal point, test with no precision set
    sprintf(buffer, "[#8: %f]", 340282346638528859811704183484516925440.82345678901234567890123456789012345678901234567890);
    puts(buffer);
    // More than maximum value, 50 digits after the decimal point, test with no precision set
    sprintf(buffer, "[#9: %f]", 3402823466385288598117041834845169254400008999.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Minumim value, test with no precision set
    sprintf(buffer, "[#10: %f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Less than minimum value after the decimal point, test with no precision set
    sprintf(buffer, "[#11: %f]", -340282346638528859811704183484516925440.723456);
    puts(buffer);
    // Less than minimum value, 50 digits after the decimal point, test with no precision set
    sprintf(buffer, "[#12: %f]", -340282346638528859811704183484516925440.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Less than minimum value, 50 digits after the decimal point, test with no precision set
    sprintf(buffer, "[#13: %f]", -3402823466385288598117041834845169254400008999.82345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Minimum value before the decimal point test with no precision set
    sprintf(buffer, "[#14: %f]", 0.);
    puts(buffer);
    // Minimum value before the decimal point with minimum value after the decimal point test with no precision set
    sprintf(buffer, "[#15: %f]", 0.0);
    puts(buffer);
    // Minimum value before the decimal point with less than 6 value after the decimal point test with no precision set
    sprintf(buffer, "[#16: %f]", 0.823);
    puts(buffer);
    // Minimum value before the decimal point with equal to 6 value after the decimal point test with no precision set
    sprintf(buffer, "[#17: %f]", 0.123456);
    puts(buffer);
    // Minimum value before the decimal point with bigger than 6 value after the decimal point test with no precision set
    sprintf(buffer, "[#18: %f]", 0.723456789);
    puts(buffer);
    // Minimum value before the decimal point with 50 digits after the decimal point test with no precision set
    sprintf(buffer, "[#19: %f]", 0.52345678901234567890123456789012345678901234567890);
    puts(buffer);
    // !!! End of regular tests with no flags

    // !!! Start of tests with width only
    // !!! Right justify with max negative value
    // Test with width being zero
    sprintf(buffer, "[#20: %0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#21: %3f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#22: %47f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#23: %55f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#23: %666f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Right justify with negative value
    // Test with width being zero
    sprintf(buffer, "[#24: %0f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#25: %3f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#26: %29f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#27: %55f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#28: %666f]", -811704183484516925440.000000);
    puts(buffer);
    // !!! Right justify with zero value
    // Test with width being zero
    sprintf(buffer, "[#29: %0f]", 0.0);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#30: %2f]", 0.0);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#31: %3f]", 0.0);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#32: %5f]", 0.0);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#33: %666f]", 0.0);
    puts(buffer);
    // !!! Right justify with regular value - less digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#34: %0f]", 1234567890.058);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#35: %2f]", 1234567890.098);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#36: %14f]", 1234567890.048);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#37: %25f]", 1234567890.098);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#38: %666f]", 1234567890.028);
    puts(buffer);
    // !!! Right justify with regular value
    // Test with width being zero
    sprintf(buffer, "[#39: %0f]", 1234567890.098765);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#40: %2f]", 1234567890.038765);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#41: %17f]", 1234567890.098765);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#42: %25f]", 1234567890.048765);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#43: %666f]", 1234567890.098765);
    puts(buffer);
    // !!! Right justify with regular value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#44: %0f]", 1234567890.0487654321);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#45: %2f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#46: %21f]", 1234567890.0387654321);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#47: %25f]", 1234567890.0987654321);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#48: %666f]", 1234567890.0287654321);
    puts(buffer);
    // !!! Right justify with max value
    // Test with width being zero
    sprintf(buffer, "[#49: %0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#50: %2f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#51: %46f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#52: %55f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#53: %666f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Right justify with max value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#54: %0f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#55: %2f]", 340282346638528859811704183484516925440.3234567890);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#56: %46f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#57: %55f]", 340282346638528859811704183484516925440.7234567890);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#58: %666f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // !!! Left-justify
    // !!! Left justify with max negative value
    // Test with width being zero
    sprintf(buffer, "[#59: %0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#60: %-3f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#61: %-47f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#62: %-55f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#63: %-666f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Left justify with negative value
    // Test with width being zero
    sprintf(buffer, "[#64: %0f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#65: %-3f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#66: %-29f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#67: %-55f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#68: %-666f]", -811704183484516925440.000000);
    puts(buffer);
    // !!! Left justify with zero value
    // Test with width being zero
    sprintf(buffer, "[#69: %0f]", 0.0);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#70: %-2f]", 0.0);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#71: %-3f]", 0.0);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#72: %-5f]", 0.0);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#73: %-666f]", 0.0);
    puts(buffer);
    // !!! Left justify with regular value - less digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#74: %0f]", 1234567890.098);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#75: %-2f]", 1234567890.038);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#76: %-14f]", 1234567890.098);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#77: %-25f]", 1234567890.018);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#78: %-666f]", 1234567890.098);
    puts(buffer);
    // !!! Left justify with regular value
    // Test with width being zero
    sprintf(buffer, "[#79: %0f]", 1234567890.048765);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#80: %-2f]", 1234567890.098765);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#81: %-17f]", 1234567890.048765);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#82: %-25f]", 1234567890.098765);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#83: %-666f]", 1234567890.038765);
    puts(buffer);
    // !!! Left justify with regular value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#84: %0f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#85: %-2f]", 1234567890.0487654321);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#86: %-21f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#87: %-25f]", 1234567890.0587654321);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#88: %-666f]", 1234567890.0987654321);
    puts(buffer);
    // !!! Left justify with max value
    // Test with width being zero
    sprintf(buffer, "[#89: %0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#90: %-2f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#91: %-46f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#92: %-55f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#93: %-666f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Left justify with max value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#94: %0f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#95: %-2f]", 340282346638528859811704183484516925440.7234567890);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#96: %-46f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#97: %-55f]", 340282346638528859811704183484516925440.8234567890);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#98: %-666f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // !!! End of tests with width only

    // !!! Start precision only
    // !!! Precision with max negative value
    // Test with precision being zero
    // More than max negative value
    sprintf(buffer, "[#99: %.0f]", -340282346638528859811704183484516925440.9234567890);
    puts(buffer);
    // Max negative value
    sprintf(buffer, "[#100: %.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Regular negative value
    sprintf(buffer, "[#101: %.0f]", -811704183484516925440.7234567890);
    puts(buffer);
    // Zero value
    sprintf(buffer, "[#102: %.0f]", 0.0);
    puts(buffer);
    // Regular value
    sprintf(buffer, "[#103: %.0f]", 1234567890.098765);
    puts(buffer);
    // Max value
    sprintf(buffer, "[#104: %.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than max value
    sprintf(buffer, "[#105: %.0f]", 340282346638528859811704183484516925440123.000000123);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    // More than max negative value
    sprintf(buffer, "[#106: %.3f]", -340282346638528859811704183484516925440.4234567890);
    puts(buffer);
    // Max negative value
    sprintf(buffer, "[#107: %.4f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Regular negative value
    sprintf(buffer, "[#108: %.5f]", -811704183484516925440.4234567890);
    puts(buffer);
    // Zero value
    sprintf(buffer, "[#109: %.3f]", 0.000000);
    puts(buffer);
    // Regular value
    sprintf(buffer, "[#110: %.1f]", 1234567890.1234567890);
    puts(buffer);
    // Max value
    sprintf(buffer, "[#111: %.3f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than max value
    sprintf(buffer, "[#112: %.4f]", 340282346638528859811704183484516925440123.7234567890);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    // More than max negative value
    sprintf(buffer, "[#113: %.10f]", -340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Max negative value
    sprintf(buffer, "[#114: %.6f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Regular negative value
    sprintf(buffer, "[#115: %.10f]", -811704183484516925440.9234567890);
    puts(buffer);
    // Zero value
    sprintf(buffer, "[#116: %.3f]", 0.000);
    puts(buffer);
    // Regular value
    sprintf(buffer, "[#117: %.10f]", 1234567890.7234567890);
    puts(buffer);
    // Regular value - 50 precision
    sprintf(buffer, "[#118: %.50f]", 1234567890.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Regular value - 50 precision - 1 digit before the dot
    sprintf(buffer, "[#119: %.50f]", 1.72345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Max value
    sprintf(buffer, "[#120: %.6f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than max value
    sprintf(buffer, "[#121: %.10f]", 340282346638528859811704183484516925440123.6234567890);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    // More than max negative value
    sprintf(buffer, "[#122: %.20f]", -340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Max negative value
    sprintf(buffer, "[#123: %.12f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Regular negative value
    sprintf(buffer, "[#124: %.20f]", -811704183484516925440.5234567890);
    puts(buffer);
    // Zero value
    sprintf(buffer, "[#125: %.6f]", 0.000);
    puts(buffer);
    // Regular value
    sprintf(buffer, "[#126: %.20f]", 1234567890.1234567890);
    puts(buffer);
    // Regular value - 50 precision
    sprintf(buffer, "[#127: %.60f]", 1234567890.52345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Regular value - 50 precision - 1 digit before the dot
    sprintf(buffer, "[#128: %.60f]", 1.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Max value
    sprintf(buffer, "[#129: %.12f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than max value
    sprintf(buffer, "[#130: %.20f]", 340282346638528859811704183484516925440123.7234567890);
    puts(buffer);
    // !!! End precision only

    // !!! Start of sign only
    // More than max negative value
    sprintf(buffer, "[#131: %+f]", -340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Max negative value
    sprintf(buffer, "[#132: %+f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Regular negative value
    sprintf(buffer, "[#133: %+f]", -811704183484516925440.1234567890);
    puts(buffer);
    // Zero value
    sprintf(buffer, "[#134: %+f]", 0.000);
    puts(buffer);
    // Regular value
    sprintf(buffer, "[#135: %+f]", 1234567890.1234567890);
    puts(buffer);
    // Regular value - 50 precision
    sprintf(buffer, "[#136: %+f]", 1234567890.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Regular value - 50 precision - 1 digit before the dot
    sprintf(buffer, "[#137: %+f]", 1.12345678901234567890123456789012345678901234567890);
    puts(buffer);
    // Max value
    sprintf(buffer, "[#138: %+f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // More than max value
    sprintf(buffer, "[#139: %+f]", 340282346638528859811704183484516925440123.1234567890);
    puts(buffer);
    // !!! End of sign only

    // !!! Start of sign and width flags together
    // !!! Sign with right justify with max negative value
    // Test with width being zero
    sprintf(buffer, "[#140: %+0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#141: %+3f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#142: %+47f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#143: %+55f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#144: %+666f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Sing right justify with negative value
    // Test with width being zero
    sprintf(buffer, "[#145: %+0f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#146: %+3f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#147: %+29f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#148: %+55f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#149: %+666f]", -811704183484516925440.000000);
    puts(buffer);
    // !!! Sign right justify with zero value
    // Test with width being zero
    sprintf(buffer, "[#150: %+0f]", 0.0);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#151: %+2f]", 0.0);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#152: %+3f]", 0.0);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#153: %+5f]", 0.0);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#154: %+666f]", 0.0);
    puts(buffer);
    // !!! Sign right justify with regular value - less digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#155: %+0f]", 1234567890.028);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#156: %+2f]", 1234567890.098);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#157: %+14f]", 1234567890.028);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#158: %+25f]", 1234567890.098);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#159: %+666f]", 1234567890.028);
    puts(buffer);
    // !!! Sign right justify with regular value
    // Test with width being zero
    sprintf(buffer, "[#160: %+0f]", 1234567890.098765);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#161: %+2f]", 1234567890.028765);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#162: %+17f]", 1234567890.098765);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#163: %+25f]", 1234567890.028765);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#164: %+666f]", 1234567890.098765);
    puts(buffer);
    // !!! Sign right justify with regular value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#165: %+0f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#166: %+2f]", 1234567890.0287654321);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#167: %+21f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#168: %+25f]", 1234567890.0287654321);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#169: %+666f]", 1234567890.0987654321);
    puts(buffer);
    // !!! Sign right justify with max value
    // Test with width being zero
    sprintf(buffer, "[#170: %+0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#171: %+2f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#172: %+46f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#173: %+55f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#174: %+666f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Sign right justify with max value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#175: %+0f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#176: %+2f]", 340282346638528859811704183484516925440.5234567890);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#177: %+46f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#178: %+55f]", 340282346638528859811704183484516925440.5234567890);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#179: %+666f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);

    // !!! Sign with left-justify
    // !!! Sign left justify with max negative value
    // Test with width being zero
    sprintf(buffer, "[#180: %+0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#181: %+-3f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#182: %+-47f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#183: %+-55f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#184: %+-666f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Sign left justify with negative value
    // Test with width being zero
    sprintf(buffer, "[#185: %+0f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#186: %+-3f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#187: %+-29f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#188: %+-55f]", -811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#189: %+-666f]", -811704183484516925440.000000);
    puts(buffer);
    // !!! Sign with left justify with zero value
    // Test with width being zero
    sprintf(buffer, "[#190: %+0f]", 0.0);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#191: %+-2f]", 0.0);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#192: %+-3f]", 0.0);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#193: %+-5f]", 0.0);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#194: %+-666f]", 0.0);
    puts(buffer);
    // !!! Sign with left justify with regular value - less digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#195: %+0f]", 1234567890.098);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#196: %+-2f]", 1234567890.038);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#197: %+-14f]", 1234567890.098);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#198: %+-25f]", 1234567890.038);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#199: %+-666f]", 1234567890.098);
    puts(buffer);
    // !!! Left justify with regular value
    // Test with width being zero
    sprintf(buffer, "[#200: %+0f]", 1234567890.038765);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#201: %+-2f]", 1234567890.098765);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#202: %+-17f]", 1234567890.038765);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#203: %+-25f]", 1234567890.098765);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#204: %+-666f]", 1234567890.038765);
    puts(buffer);
    // !!! Sign with left justify with regular value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#205: %+0f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#206: %+-2f]", 1234567890.0387654321);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#207: %+-21f]", 1234567890.0987654321);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#208: %+-25f]", 1234567890.0387654321);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#209: %+-666f]", 1234567890.0987654321);
    puts(buffer);
    // !!! Sign with left justify with max value
    // Test with width being zero
    sprintf(buffer, "[#210: %+0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#211: %+-2f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#212: %+-46f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#213: %+-55f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#214: %+-666f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! Sign with left justify with max value - more digits after the dot than 6
    // Test with width being zero
    sprintf(buffer, "[#215: %+0f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being less than the vrgp
    sprintf(buffer, "[#216: %+-2f]", 340282346638528859811704183484516925440.6234567890);
    puts(buffer);
    // Test with width being equal to the vrgp
    sprintf(buffer, "[#217: %+-46f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // Test with width being more than the vrgp
    sprintf(buffer, "[#218: %+-55f]", 340282346638528859811704183484516925440.6234567890);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#219: %+-666f]", 340282346638528859811704183484516925440.1234567890);
    puts(buffer);
    // !!! End of sign and width flags together

    // !!! Begging of sign and precision together tests
    // !!! Precision with minimum possible value
    // Test with precision being zero
    sprintf(buffer, "[#220: %+.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#221: %+.3f]", -340282346638528859811704183484516925439.123456);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#222: %+.6f]", -340282346638528859811704183484516925439.823456);
    puts(buffer);
    // Test with precision being bigger than the amount of digits after the dot
    sprintf(buffer, "[#223: %+.9f]", -340282346638528859811704183484516925439.123456);
    puts(buffer);
    // Test with 2-digit precision
    sprintf(buffer, "[#224: %+.14f]", -340282346638528859811704183484516925439.823456);
    puts(buffer);
    // Test with 3-digit precision
    sprintf(buffer, "[#225: %+.114f]", -340282346638528859811704183484516925439.123456);
    puts(buffer);
    // !!! Precision with negative value
    // Test with precision being zero
    sprintf(buffer, "[#226: %+.0f]", -811704183484516925440.9876544321);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#227: %+-.4f]", -811704183484516925440.3876544321);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#228: %+.10f]", -811704183484516925440.9876544321);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#229: %+.11f]", -811704183484516925440.3876544321);
    puts(buffer);
    // Test with 2-digit width
    sprintf(buffer, "[#230: %+.14f]", -811704183484516925440.9876544321);
    puts(buffer);
    // Test with 3-digit width
    sprintf(buffer, "[#230: %+.114f]", -811704183484516925440.3876544321);
    puts(buffer);
    // !!! Sign with precision with zero value
    // Test with precision being zero
    sprintf(buffer, "[#231: %+.0f]", 0.0);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#232: %+.1f]", 0.0);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#233: %+.5f]", 0.0);
    puts(buffer);
    // Test with 2-digit precision
    sprintf(buffer, "[#234: %+.26f]", 0.0);
    puts(buffer);
    // !!! Sign with precision with regular value - less digits after the dot than 6
    // Test with precision being zero
    sprintf(buffer, "[#235: %+.0f]", 1234567890.038);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#236: %+.2f]", 1234567890.098);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#237: %+.3f]", 1234567890.038);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#238: %+.5f]", 1234567890.098);
    puts(buffer);
    // Test with 2-digit precision
    sprintf(buffer, "[#239: %+.14f]", 1234567890.038);
    puts(buffer);
    // Test with 3-digit precision
    sprintf(buffer, "[#240: %+.114f]", 1234567890.098);
    puts(buffer);
    // !!! Precision with regular value
    // Test with precision being zero
    sprintf(buffer, "[#241: %+.0f]", 1234567890.098765);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#242: %+.2f]", 1234567890.038765);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#243: %+.4f]", 1234567890.098765);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#244: %+.9f]", 1234567890.038765);
    puts(buffer);
    // Test with 2-digit precision
    sprintf(buffer, "[#245: %+.24f]", 1234567890.098765);
    puts(buffer);
    // Test with 3-digit precision
    sprintf(buffer, "[#246: %+.243f]", 1234567890.038765);
    puts(buffer);
    // !!! Sign with precision with regular value - more digits after the dot than 6
    // Test with precision being zero
    sprintf(buffer, "[#247: %+.0f]", 1234567890.0987654321);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#248: %+.4f]", 1234567890.0387654321);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#249: %+.10f]", 1234567890.0987654321);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#250: %+.25f]", 1234567890.0487654321);
    puts(buffer);
    // Test with 3-digit precision
    sprintf(buffer, "[#251: %+.116f]", 1234567890.0987654321);
    puts(buffer);
    // !!! Sign with precisiom with max value
    // Test with precision being zero
    sprintf(buffer, "[#252: %+.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Test with precision being less than the amount of digits after the dot
    sprintf(buffer, "[#253: %+.2f]", 340282346638528859811704183484516925439.6758943345);
    puts(buffer);
    // Test with precision being equal to the amount of digits after the dot
    sprintf(buffer, "[#254: %+.10f]", 340282346638528859811704183484516925439.3758943345);
    puts(buffer);
    // Test with precision being more than the amount of digits after the dot
    sprintf(buffer, "[#255: %+.15f]", 340282346638528859811704183484516925439.6758943345);
    puts(buffer);
    // Test with 3-digit precision
    sprintf(buffer, "[#256: %+.106f]", 340282346638528859811704183484516925439.3758943345);
    puts(buffer);
    // !!! End of sign and precision together tests

    // !!! Begging of width and precision together tests
    // Precision and width being zero with max negative value
    sprintf(buffer, "[#257: %0.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Precision and width being zero with negative value
    sprintf(buffer, "[#258: %0.0f]", -516925439.3758943345);
    puts(buffer);
    // Precision and width being zero with zero
    sprintf(buffer, "[#259: %0.0f]", 0.0);
    puts(buffer);
    // Precision and width being zero with positive value
    sprintf(buffer, "[#260: %0.0f]", 516925439.8758943345);
    puts(buffer);
    // Precision and width being zero with max positive value
    sprintf(buffer, "[#261: %0.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to the argp and precision zero with max negative value
    sprintf(buffer, "[#262: %40.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to the argp and precision zero with negative value
    sprintf(buffer, "[#263: %9.0f]", -12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to the argp and width being zero with zero
    sprintf(buffer, "[#264: %1.0f]", 0.0);
    puts(buffer);
    // Width (right-justify) equal to the argp and precision zero with positive value
    sprintf(buffer, "[#265: %8.0f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to the argp and precision zero with max positive value
    sprintf(buffer, "[#266: %39.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) bigger than the argp and precision zero with max negative value
    sprintf(buffer, "[#267: %50.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) bigger than the argp and precision zero with negative value
    sprintf(buffer, "[#268: %21.0f]", -12346487.2355467865);
    puts(buffer);
    // Width (right-justify) bigger than the argp and width being zero with zero
    sprintf(buffer, "[#269: %15.0f]", 0.0);
    puts(buffer);
    // Width (right-justify) bigger than the argp and precision zero with positive value
    sprintf(buffer, "[#270: %78.0f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) bigger than the argp and precision zero with max positive value
    sprintf(buffer, "[#271: %89.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) equal to the argp and precision zero with max negative value
    sprintf(buffer, "[#272: %-40.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) equal to the argp and precision zero with negative value
    sprintf(buffer, "[#273: %-9.0f]", -12346487.2355467865);
    puts(buffer);
    // Width (left-justify) equal to the argp and width being zero with zero
    sprintf(buffer, "[#274: %-1.0f]", 0.0);
    puts(buffer);
    // Width (left-justify) equal to the argp and precision zero with positive value
    sprintf(buffer, "[#275: %-8.0f]", 12346487.2355467865);
    puts(buffer);
    // Width (left-justify) equal to the argp and precision zero with max positive value
    sprintf(buffer, "[#276: %-39.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) bigger than the argp and precision zero with max negative value
    sprintf(buffer, "[#277: %-50.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) bigger than the argp and precision zero with negative value
    sprintf(buffer, "[#279: %-21.0f]", -12346487.2355467865);
    puts(buffer);
    // Width (left-justify) bigger than the argp and width being zero with zero
    sprintf(buffer, "[#280: %-15.0f]", 0.0);
    puts(buffer);
    // Width (left-justify) bigger than the argp and precision zero with positive value
    sprintf(buffer, "[#281: %-78.0f]", 12346487.2355467865);
    puts(buffer);
    // Width (left-justify) bigger than the argp and precision zero with max positive value
    sprintf(buffer, "[#282: %-89.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision less than max negative value
    sprintf(buffer, "[#283: %0.1f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision less than negative value
    sprintf(buffer, "[#284: %0.2f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision less than zero
    sprintf(buffer, "[#285: %0.3f]", 0.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision less than positive value
    sprintf(buffer, "[#286: %0.4f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision less than max positive value
    sprintf(buffer, "[#287: %0.5f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision equal to max negative value
    sprintf(buffer, "[#288: %0.6f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision equal to negative value
    sprintf(buffer, "[#289: %0.10f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision equal to zero
    sprintf(buffer, "[#290: %0.9f]", 0.000000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision equal to positive value
    sprintf(buffer, "[#291: %0.10f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision equal to max positive value
    sprintf(buffer, "[#292: %0.6f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision bigger than to max negative value
    sprintf(buffer, "[#293: %0.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision bigger than negative value
    sprintf(buffer, "[#294: %0.115f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision bigger than zero
    sprintf(buffer, "[#295: %0.9f]", 0.000000000);
    puts(buffer);
    // Width (right-justify) equal to zero and precision bigger than positive value
    sprintf(buffer, "[#296: %0.69f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to zero and precision bigger than max positive value
    sprintf(buffer, "[#297: %0.30f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to precision with max negative value
    sprintf(buffer, "[#298: %8.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) equal to precision with negative value
    sprintf(buffer, "[#299: %11.11f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) equal to precision with than zero
    sprintf(buffer, "[#300: %30.30f]", 0.000000000);
    puts(buffer);
    // Width (right-justify) equal to precision with positive value
    sprintf(buffer, "[#301: %40.40f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) equal to precision with max positive value
    sprintf(buffer, "[#302: %111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) equal to precision with max negative value
    sprintf(buffer, "[#303: %-8.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) equal to precision with negative value
    sprintf(buffer, "[#304: %-11.11f]", -12346487.8355467865);
    puts(buffer);
    // Width (left-justify) equal to precision with than zero
    sprintf(buffer, "[#305: %-30.30f]", 0.000000000);
    puts(buffer);
    // Width (left-justify) equal to precision with positive value
    sprintf(buffer, "[#306: %-40.40f]", 12346487.2355467865);
    puts(buffer);
    // Width (left-justify) equal to precision with max positive value
    sprintf(buffer, "[#307: %-111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) bigger than the precision with max negative value
    sprintf(buffer, "[#308: %9.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) bigger than the precision with negative value
    sprintf(buffer, "[#309: %13.11f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) bigger than the precision with than zero
    sprintf(buffer, "[#310: %30.30f]", 0.000000000);
    puts(buffer);
    // Width (right-justify) bigger than the precision with positive value
    sprintf(buffer, "[#311: %41.40f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) bigger than the precision with max positive value
    sprintf(buffer, "[#312: %111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) bigger than the precision with max negative value
    sprintf(buffer, "[#313: %-9.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) bigger than the precision with negative value
    sprintf(buffer, "[#314: %-13.11f]", -12346487.8355467865);
    puts(buffer);
    // Width (left-justify) bigger than the precision with than zero
    sprintf(buffer, "[#315: %-36.30f]", 0.000000000);
    puts(buffer);
    // Width (left-justify) bigger than the precision with positive value
    sprintf(buffer, "[#316: %-49.40f]", 12346487.2355467865);
    puts(buffer);
    // Width (left-justify) bigger than the precision with max positive value
    sprintf(buffer, "[#317: %-215.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) less than the precision with max negative value
    sprintf(buffer, "[#318: %9.11f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (right-justify) less than the precision with negative value
    sprintf(buffer, "[#319: %13.16f]", -12346487.8355467865);
    puts(buffer);
    // Width (right-justify) less than the precision with than zero
    sprintf(buffer, "[#320: %30.33f]", 0.000000000);
    puts(buffer);
    // Width (right-justify) less than the precision with positive value
    sprintf(buffer, "[#321: %41.48f]", 12346487.2355467865);
    puts(buffer);
    // Width (right-justify) less than the precision with max positive value
    sprintf(buffer, "[#322: %111.156f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) less than the precision with max negative value
    sprintf(buffer, "[#323: %-9.13f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Width (left-justify) less than the precision with negative value
    sprintf(buffer, "[#324: %-13.18f]", -12346487.8355467865);
    puts(buffer);
    // Width (left-justify) less than the precision with than zero
    sprintf(buffer, "[#315: %-36.46f]", 0.000000000);
    puts(buffer);
    // Width (left-justify) less than the precision with positive value
    sprintf(buffer, "[#316: %-49.78f]", 12346487.2355467865);
    puts(buffer);
    // Width (left-justify) less than the precision with max positive value
    sprintf(buffer, "[#317: %-215.311f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! End of sign and precision together tests

    // !!! Start of sign, precision and width together tests
    // Sign, precision and width being zero with max negative value
    sprintf(buffer, "[#318: %+0.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, precision and width being zero with negative value
    sprintf(buffer, "[#319: %+0.0f]", -516925439.3758943345);
    puts(buffer);
    // Sign, precision and width being zero with zero
    sprintf(buffer, "[#320: %+0.0f]", 0.0);
    puts(buffer);
    // Sign, precision and width being zero with positive value
    sprintf(buffer, "[#321: %+0.0f]", 516925439.8758943345);
    puts(buffer);
    // Sign, precision and width being zero with max positive value
    sprintf(buffer, "[#322: %+0.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to the argp and precision zero with max negative value
    sprintf(buffer, "[#323: %+40.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to the argp and precision zero with negative value
    sprintf(buffer, "[#324: %+9.0f]", -12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to the argp and width being zero with zero
    sprintf(buffer, "[#325: %+1.0f]", 0.0);
    puts(buffer);
    // Sign, width (right-justify) equal to the argp and precision zero with positive value
    sprintf(buffer, "[#326: %+8.0f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to the argp and precision zero with max positive value
    sprintf(buffer, "[#327: %+39.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) bigger than the argp and precision zero with max negative value
    sprintf(buffer, "[#328: %+50.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) bigger than the argp and precision zero with negative value
    sprintf(buffer, "[#329: %+21.0f]", -12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) bigger than the argp and width being zero with zero
    sprintf(buffer, "[#330: %+15.0f]", 0.0);
    puts(buffer);
    // Sign, width (right-justify) bigger than the argp and precision zero with positive value
    sprintf(buffer, "[#331: %+78.0f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) bigger than the argp and precision zero with max positive value
    sprintf(buffer, "[#332: %+89.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) equal to the argp and precision zero with max negative value
    sprintf(buffer, "[#333: %+-40.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) equal to the argp and precision zero with negative value
    sprintf(buffer, "[#334: %+-9.0f]", -12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) equal to the argp and width being zero with zero
    sprintf(buffer, "[#335: %+-1.0f]", 0.0);
    puts(buffer);
    // Sign, width (left-justify) equal to the argp and precision zero with positive value
    sprintf(buffer, "[#336: %+-8.0f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) equal to the argp and precision zero with max positive value
    sprintf(buffer, "[#337: %+-39.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) bigger than the argp and precision zero with max negative value
    sprintf(buffer, "[#338: %+-50.0f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) bigger than the argp and precision zero with negative value
    sprintf(buffer, "[#339: %+-21.0f]", -12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) bigger than the argp and width being zero with zero
    sprintf(buffer, "[#340: %+-15.0f]", 0.0);
    puts(buffer);
    // Sign, width (left-justify) bigger than the argp and precision zero with positive value
    sprintf(buffer, "[#341: %+-78.0f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) bigger than the argp and precision zero with max positive value
    sprintf(buffer, "[#342: %+-89.0f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision less than max negative value
    sprintf(buffer, "[#343: %+0.1f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision less than negative value
    sprintf(buffer, "[#344: %+0.2f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision less than zero
    sprintf(buffer, "[#345: %+0.3f]", 0.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision less than positive value
    sprintf(buffer, "[#346: %+0.4f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision less than max positive value
    sprintf(buffer, "[#347: %+0.5f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision equal to max negative value
    sprintf(buffer, "[#348: %+0.6f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision equal to negative value
    sprintf(buffer, "[#349: %+0.10f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision equal to zero
    sprintf(buffer, "[#350: %+0.9f]", 0.000000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision equal to positive value
    sprintf(buffer, "[#351: %+0.10f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision equal to max positive value
    sprintf(buffer, "[#352: %+0.6f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision bigger than to max negative value
    sprintf(buffer, "[#353: %+0.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision bigger than negative value
    sprintf(buffer, "[#354: %+0.115f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision bigger than zero
    sprintf(buffer, "[#355: %+0.9f]", 0.000000000);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision bigger than positive value
    sprintf(buffer, "[#356: %+0.69f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to zero and precision bigger than max positive value
    sprintf(buffer, "[#357: %+0.30f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to precision with max negative value
    sprintf(buffer, "[#358: %+8.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) equal to precision with negative value
    sprintf(buffer, "[#359: %+11.11f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to precision with than zero
    sprintf(buffer, "[#360: %+30.30f]", 0.000000000);
    puts(buffer);
    // Sign, width (right-justify) equal to precision with positive value
    sprintf(buffer, "[#361: %+40.40f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) equal to precision with max positive value
    sprintf(buffer, "[#362: %+111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) equal to precision with max negative value
    sprintf(buffer, "[#363: %+-8.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, idth (left-justify) equal to precision with negative value
    sprintf(buffer, "[#364: %+-11.11f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (left-justify) equal to precision with than zero
    sprintf(buffer, "[#365: %+-30.30f]", 0.000000000);
    puts(buffer);
    // Sign, width (left-justify) equal to precision with positive value
    sprintf(buffer, "[#366: %+-40.40f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) equal to precision with max positive value
    sprintf(buffer, "[#367: %+-111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) bigger than the precision with max negative value
    sprintf(buffer, "[#368: %+9.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) bigger than the precision with negative value
    sprintf(buffer, "[#369: %+13.11f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) bigger than the precision with than zero
    sprintf(buffer, "[#370: %+30.30f]", 0.000000000);
    puts(buffer);
    // Sign, width (right-justify) bigger than the precision with positive value
    sprintf(buffer, "[#371: %+41.40f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) bigger than the precision with max positive value
    sprintf(buffer, "[#372: %+111.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) bigger than the precision with max negative value
    sprintf(buffer, "[#373: %+-9.8f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) bigger than the precision with negative value
    sprintf(buffer, "[#374: %+-13.11f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (left-justify) bigger than the precision with than zero
    sprintf(buffer, "[#375: %+-36.30f]", 0.000000000);
    puts(buffer);
    // Sign, width (left-justify) bigger than the precision with positive value
    sprintf(buffer, "[#376: %+-49.40f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) bigger than the precision with max positive value
    sprintf(buffer, "[#377: %+-215.111f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) less than the precision with max negative value
    sprintf(buffer, "[#378: %+9.11f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (right-justify) less than the precision with negative value
    sprintf(buffer, "[#379: %+13.16f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (right-justify) less than the precision with than zero
    sprintf(buffer, "[#380: %+30.33f]", 0.000000000);
    puts(buffer);
    // Sign, width (right-justify) less than the precision with positive value
    sprintf(buffer, "[#381: %+41.48f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (right-justify) less than the precision with max positive value
    sprintf(buffer, "[#382: %+111.156f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) less than the precision with max negative value
    sprintf(buffer, "[#383: %+-9.13f]", -340282346638528859811704183484516925440.000000);
    puts(buffer);
    // Sign, width (left-justify) less than the precision with negative value
    sprintf(buffer, "[#384: %+-13.18f]", -12346487.8355467865);
    puts(buffer);
    // Sign, width (left-justify) less than the precision with than zero
    sprintf(buffer, "[#385: %+-36.46f]", 0.000000000);
    puts(buffer);
    // Sign, width (left-justify) less than the precision with positive value
    sprintf(buffer, "[#386: %+-49.78f]", 12346487.2355467865);
    puts(buffer);
    // Sign, width (left-justify) less than the precision with max positive value
    sprintf(buffer, "[#387: %+-215.311f]", 340282346638528859811704183484516925440.000000);
    puts(buffer);
    // !!! End of sign, precision and width together tests

    return 0;
}
