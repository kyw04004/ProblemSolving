class Solution {
    public int[] solution(int[] answers) {
        int Max = 0;
        int[] answer = {};
        int[] one = {1,2,3,4,5}; 
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
        int[] score = new int[3];
        for(int i=0;i<answers.length;i++) {
            int aI = i % 5, bI = i % 8, cI = i % 10;
            if(one[aI] == answers[i]) score[0]++;
            if(two[bI] == answers[i]) score[1]++;
            if(three[cI] == answers[i]) score[2]++;
        }
        int cnt = 0;
        for(int i=0;i<3;i++)
            if(score[i] > Max) Max = score[i];
        for(int i=0;i<3;i++)
            if(score[i] == Max) cnt++;
        answer = new int[cnt];
        for(int i=0,j=0;i<3;i++)
            if(score[i] == Max) answer[j++] = i+1;
        return answer;
    }
}