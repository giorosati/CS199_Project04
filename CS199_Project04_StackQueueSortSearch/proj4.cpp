#include <iostream>
#include <cstdlib>
#include "myLL.hpp"
#include "myStack.hpp"
#include "myQueue.hpp"
#include "monster.hpp"

#include "goblin.hpp"
#include "troll.hpp"
#include "dragon.hpp"
#include "icedragon.hpp"
#include "firedragon.hpp"

void displayMenu();
int getInput();
Monster* addMonster();

int main() {
  myLL list;
  myStack stack;
  myQueue queue;
  bool done = false;
  int choice = 0;
  Monster *tempMonster = NULL;
  while(done != true) {
    displayMenu();
    choice = getInput();
    switch(choice) {
    case 1:
      list.displayList();
      break;
    case 2:
      tempMonster = addMonster();
      list.addValue(tempMonster);
      break;
    case 3:
      list.removeLast();
      break;
    case 4:
      std::cout << std::endl;
      list.sort();
      break;
    case 5:
      {
	std::string searchVal;
	std::cout << "What type of monster do you want to search for? ";
	std::cin.ignore();
	std::getline(std::cin, searchVal);
	if( list.search(searchVal)) {
	  std::cout << searchVal << " is in the list." << std::endl;
	} else {
	  std::cout << searchVal << " is not in the list." << std::endl;
	}
	break;
      }
    case 6:
      tempMonster = stack.peek();
      if(tempMonster == NULL) {
	std::cout << "Stack Empty" << std::endl;
      } else {
	std::cout << "Top Monster Type: " <<  tempMonster->getType() << std::endl;
      }
      break;
    case 7:
      tempMonster = addMonster();
      stack.push(tempMonster);
      break;
    case 8:
      stack.pop();
      break;
    case 9:
      tempMonster = queue.peekFirst();
      if(tempMonster == NULL ) {
	std::cout << "Queue Empty" << std::endl;
      } else {
	std::cout << "First Monster Type: " << tempMonster->getType() << std::endl;
      }
      break;
    case 10:
      tempMonster = queue.peekLast();
      if(tempMonster == NULL ) {
	std::cout << "Queue Empty" << std::endl;
      } else {
	std::cout << "Last Monster Type: " << tempMonster->getType() << std::endl;
      }
      break;
    case 11:
      tempMonster = addMonster();
      queue.enqueue(tempMonster);
      break;
    case 12:
      queue.dequeue();
      break;
    case 0:
      done = true;
      break;
    default:
      std::cout << "Not a valid choice" << std::endl;
      break;
    }
  }
}


void displayMenu() {
  std::cout << std::endl;
  std::cout << "What would you like to do?" << std::endl;
  std::cout << "0) Quit" << std::endl;
  std::cout << "******myLL Options*******" << std::endl;
  std::cout << "1) Display list" << std::endl;
  std::cout << "2) Add Monster" << std::endl;
  std::cout << "3) Remove Last Monster" << std::endl;
  std::cout << "4) Sort Monsters" << std::endl;
  std::cout << "5) Search Monsters" << std::endl;
  std::cout << "******myStack Options****" << std::endl;
  std::cout << "6) Peek" << std::endl;
  std::cout << "7) Push" << std::endl;
  std::cout << "8) Pop" << std::endl;
  std::cout << "******myQueue Options****" << std::endl;
  std::cout << "9) Peek First" << std::endl;
  std::cout << "10) Peek Last" << std::endl;
  std::cout << "11) Enqueue" << std::endl;
  std::cout << "12) Dequeue" << std::endl;

}

int getInput() {
  int choice;
  std::cout << "Choice: ";
  std::cin >> choice;
  return choice;
}

Monster* addMonster() {
  int monsterType;
  Monster *temp = NULL;
  std::cout << "What type of Monster do you wish to add?" << std::endl;
  std::cout << "1) Goblin" << std::endl;
  std::cout << "2) Troll" << std::endl;
  std::cout << "3) Dragon" << std::endl;
  std::cout << "4) Ice Dragon" << std::endl;
  std::cout << "5) Fire Dragon" << std::endl;

  do {
    std::cout << "Choice: ";
    std::cin >> monsterType;
    switch(monsterType) {
    case 1:
      return new Goblin;
    case 2:
      return new Troll;
    case 3:
      return new Dragon;
    case 4:
      return new IceDragon;
    case 5:
      return new FireDragon;
    default:
      std::cout << "Not a valid choice, try again" << std::endl;
      break;
    }
  }while(true);
}
