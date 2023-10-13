// 875. Koko Eating Bananas

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.


// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30


public class KokoEatingBananas {
    public static void main(String[] args) {
        

        // Example usage:
        int[] piles = {3, 6, 7, 11};
        int h = 8;
        int minEatingSpeed = minEatingSpeed(piles, h);

        System.out.println("Minimum Eating Speed: " + minEatingSpeed);
    }

    static public int minEatingSpeed(int[] piles, int h) {
            int left=1;
            int right = 1000000000;
            while(left<right)
            {
                int m = left+(right-left)/2;
                if(canEat(piles,m,h)) right=m;
                else left = m+1;
            }
            return left; 
        }

        private static boolean canEat(int[] piles,int k, int h)
        {
            int hours=0;
            for(int pile:piles)
            {
                int div = pile/k;
                hours+=div;
                if(pile%k!=0) hours++;
            }
            return hours<=h;
        }


}
