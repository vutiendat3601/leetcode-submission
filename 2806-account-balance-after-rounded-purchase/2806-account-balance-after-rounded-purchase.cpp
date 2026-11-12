class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - round(purchaseAmount / 10.0) * 10;
    }
};