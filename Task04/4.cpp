#include <iostream> 
#include <vector> 
#include <map> 
#include <algorithm> 
 
int main() { 
   
    int n, m; 
    std::cin >> n >> m; 
     
     
    std::vector<std::string> songs(n); 
    for (int i = 0; i < n; i++) { 
        std::cin >> songs[i]; 
    } 
     
    
    std::map<std::string, int> wordCount; 
     
     
    for (int i = 0; i < n; i++) { 
        std::string song = songs[i]; 
        std::string word = ""; 
         
       
        for (int j = 0; j < song.length(); j++) { 
            if (song[j] == ' ') { 
                 
                wordCount[word]++; 
                word = ""; 
            } else { 
              
                word += song[j]; 
            } 
        } 
         
        
        wordCount[word]++; 
    } 
     
    
    std::vector<std::pair<int, std::string>> wordFreq; 
     
     
    for (auto it = wordCount.begin(); it != wordCount.end(); it++) { 
        wordFreq.push_back(std::make_pair(it->second, it->first)); 
    } 
     
    
    std::sort(wordFreq.rbegin(), wordFreq.rend()); 
     
 
    for (int i = 0; i < m; i++) { 
        std::cout << wordFreq[i].second << std::endl; 
    } 
     
    return 0; 
}
