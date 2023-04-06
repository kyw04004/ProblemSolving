import java.util.*;
import java.util.stream.Collectors;
class Solution {
    public String solution(int[] numbers) {
        StringBuilder answer= new StringBuilder();
        List<String> arr = new ArrayList<>();
        for (int number : numbers) {
            arr.add(String.valueOf(number));
        }
        arr = arr.stream().sorted((a, b) -> {
            String ab = a+b;
            String ba = b+a;
            Integer abNum = Integer.valueOf(ab);
            Integer baNum = Integer.valueOf(ba);
            return baNum - abNum;
        }).collect(Collectors.toList());
        for (String s : arr) {
            if (answer.toString().equals("") && s.equals("0")) continue;
            answer.append(s);
        }
        if(answer.toString().equals("")) return "0";
        return answer.toString();
    }
}