class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        
        return num%9 == 0 ? 9 : num%9;
    }
};

//class Solution {
//public:
//    int addDigits(int num) {
//        int sum = 0;
//
//        while(num>9)
//        {
//            while(num)
//            {
//                int rem = num%10;
//                sum += rem;
//                num /= 10;
//            }
//
//            num = sum;
//            sum = 0;
//        }
//
//        return num;
//    }
//};
