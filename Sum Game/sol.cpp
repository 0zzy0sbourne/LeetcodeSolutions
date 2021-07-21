class Solution {
public:
    bool sumGame(string num) {
        // while ? exists : 
        
        // out of while: 
        // check if first and second half are equal: 
        // if equal : 
        int length = num.length(); 
        int diff = 0 ;  
        int count = 0 ;
        
        for(int i = 0;i<length;i++){
            if(num[i] == '?'){
                count += i < length/2 ? 1 : -1; 
            }
            else {
                if(i<length/2){
                    diff += num[i] - '0'; 
                }
                else{
                    diff -= num[i] - '0'; 
                }
            }
        }
        if((diff) * 2  == count * -9){
            return false ; 
        }
        return true ; 
        
    
    }
};