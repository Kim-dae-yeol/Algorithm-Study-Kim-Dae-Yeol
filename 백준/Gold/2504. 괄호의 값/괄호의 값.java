import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String arr = br.readLine();

        int temp_answer = 1;
        int answer = 0;

        Stack<Character> stack  = new Stack<>();
        for(int i = 0; i < arr.length(); i++){
            char temp = arr.charAt(i);

            if( temp == '(') {
                stack.push('(');
                temp_answer *= 2;
            }else if(temp == '['){
                stack.push('[');
                temp_answer *= 3;
            }else if(temp == ')'){
                if(stack.isEmpty() || stack.peek() != '('){
                    System.out.println(0);
                    return;
                }else{
                     if(arr.charAt(i-1) == '(') answer += temp_answer;
                     stack.pop();
                     temp_answer /= 2;
                }
            }else if(temp == ']'){
                if(stack.isEmpty() || stack.peek() != '['){
                    System.out.println(0);
                    return;
                }else {
                    if(arr.charAt(i-1) == '[') answer += temp_answer;
                    stack.pop();
                    temp_answer /= 3;
                }
            }

        }
        if(stack.isEmpty()){
            System.out.println(answer);
        }else {
            System.out.println("0");
        }
    }
}
