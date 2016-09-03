class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = abs(A-C)*abs(B-D)+abs(E-G)*abs(F-H);
        if (E >= C || G <= A || F >= D || H <= B) return a;
        return a-(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
    }
};