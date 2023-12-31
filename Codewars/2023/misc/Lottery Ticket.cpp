/*
 * Time to win the lottery!
 * 
 * Given a lottery ticket (ticket), represented by an array of 2-value arrays, you must find out if you've won the jackpot.
 * 
 * Example ticket:
 * 
 * { { "ABC", 65 }, { "HGR", 74 }, { "BYHT", 74 } }
 * To do this, you must first count the 'mini-wins' on your ticket. Each subarray has both a string and a number within it. If the character code of any of the characters in the string matches the number, you get a mini win. Note you can only have one mini win per sub array.
 * 
 * Once you have counted all of your mini wins, compare that number to the other input provided (win). If your total is more than or equal to (win), return 'Winner!'. Else return 'Loser!'.
 * 
 * All inputs will be in the correct format. Strings on tickets are not always the same length.
 */
#include <string>
#include <vector>
#include <utility>

std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win) {
  int miniWin = 0;
  
  for (size_t i = 0; i < ticket.size(); i++) {
    std::string temp = ticket[i].first;
    
    for (size_t j = 0; j < temp.length(); j++)
      if (int(temp[j]) == ticket[i].second)
        miniWin += 1;
  }
  
  return miniWin >= win ? "Winner!" : "Loser!";
}

// ALTERNATIVE
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win) {
    return std::count_if(ticket.begin(), ticket.end(), [](const auto& i) {
        return std::any_of(i.first.begin(), i.first.end(), [&](const char& j) { return j == i.second; });
    }) >= win ? "Winner!" : "Loser!" ;
}
