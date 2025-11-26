#pragma once
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

namespace my_list {

   struct Student {
       int id = 0;
       std::string name = "";
       std::string father_name = "";
       std::string contact = "";
       int semester = 0;
       float cgpa = 0.0;
   };

   template<typename T>
   struct node {
       T data;
       node<T>* next;
   };

   template<typename T>
   class list {
   private:
       node<T>* H;
       int n;

   public:
       list() {
           H = new node<T>;
           H->next = H;
           n = 0;
       }

       ~list() {
           clear();
           delete H;
       }

       void insert_at_start(const T& value) {
           node<T>* temp = new node<T>{ value, H->next };
           H->next = temp;
           n++;
       }

       void insert_at_end(const T& value) {
           node<T>* curr = H;
           while (curr->next != H)
               curr = curr->next;
           node<T>* temp = new node<T>{ value, H };
           curr->next = temp;
           n++;
       }

       void insert_after(int id, const T& value) {
           node<T>* curr = H->next;
           while (curr != H) {
               if (curr->data.id == id) {
                   node<T>* temp = new node<T>{ value, curr->next };
                   curr->next = temp;
                   n++;
                   return;
               }
               curr = curr->next;
           }
           throw std::exception("ID does not found.");
       }

       void delete_at_start() {
           if (H->next == H)
               throw std::exception("List is empty.");
           node<T>* temp = H->next;
           H->next = temp->next;
           delete temp;
           n--;
       }

       void delete_at_end() {
           if (H->next == H)
               throw std::exception("List is empty.");
           node<T>* prev = H, * curr = H->next;
           while (curr->next != H) {
               prev = curr;
               curr = curr->next;
           }
           prev->next = H;
           delete curr;
           n--;
       }

       void delete_by_id(int id) {
           node<T>* prev = H, * curr = H->next;
           while (curr != H) {
               if (curr->data.id == id) {
                   prev->next = curr->next;
                   delete curr;
                   n--;
                   return;
               }
               prev = curr;
               curr = curr->next;
           }
           throw std::exception("ID does not found.");
       }

       void search_by_id(int id) {
           node<T>* curr = H->next;
           while (curr != H) {
               if (curr->data.id == id) {
                   std::cout << "\n\n\t\t\t\t\tData Found :\n";
                   std::cout << "\t\t*********************************************************\n";
                   std::cout << std::left
                       << std::setw(6) << "ID" << " | " << std::setw(20) << "Name" << " | "
                       << std::setw(22) << "Father Name" << " | " << std::setw(13) << "Contact" << " | "
                       << std::setw(9) << "Semester" << " | " << "CGPA" << " |\n";
                   std::cout << "-----------------------------------------------------------------------------------------\n";

                   std::cout << std::left
                       << std::setw(6) << curr->data.id << " | " << std::setw(20) << curr->data.name << " | "
                       << std::setw(22) << curr->data.father_name << " | " << std::setw(13) << curr->data.contact << " | "
                       << std::setw(9) << curr->data.semester << " | "
                       << std::fixed << std::setprecision(2) << curr->data.cgpa << " |\n";

                   std::cout << "-----------------------------------------------------------------------------------------\n";
                   return;
               }
               curr = curr->next;
           }
           throw std::exception("ID not found.");
       }


       void modify_by_id(int id) {
           node<T>* curr = H->next;
           while (curr != H) {
               if (curr->data.id == id) {
                   std::cin.ignore(); 
                   std::cout << "Enter new name: ";
                   std::getline(std::cin, curr->data.name);
                   std::cout << "Enter new father's name: ";
                   std::getline(std::cin, curr->data.father_name);
                   std::cout << "Enter new contact: ";
                   std::getline(std::cin, curr->data.contact);
                   std::cout << "Enter new semester: ";
                   std::cin >> curr->data.semester;
                   std::cout << "Enter new CGPA: ";
                   std::cin >> curr->data.cgpa;
                   std::cout << "Modified successfully.\n";
                   return;
               }
               curr = curr->next;
           }
           throw std::exception("ID does not found.");
       }

       void sort_by_id() {
           if (n < 2) return;
           for (node<T>* i = H->next; i->next != H; i = i->next) {
               for (node<T>* j = i->next; j != H; j = j->next) {
                   if (i->data.id > j->data.id) {
                       std::swap(i->data, j->data);
                   }
               }
           }
           std::cout << "List sorted by ID.\n";
       }

       void display() {
           if (H->next == H) {
               std::cout << "List is empty.\n";
               return;
           }
           node<T>* curr = H->next;
           std::cout << "\n\n\t\t\t\t\tStudent List:\n";
           std::cout << "\t\t*********************************************************\n";
           std::cout << std::left
               << std::setw(6) << "ID" << " | " << std::setw(20) << "Name" << " | "
               << std::setw(22) << "Father Name" << " | " << std::setw(13) << "Contact" << " | "
               << std::setw(9) << "Semester" << " | " << "CGPA" << " |\n";
           std::cout << "-----------------------------------------------------------------------------------------\n";
           while (curr != H) {

               std::cout << std::left
                   << std::setw(6) << curr->data.id << " | " << std::setw(20) << curr->data.name << " | "
                   << std::setw(22) << curr->data.father_name << " | " << std::setw(13) << curr->data.contact << " | "
                   << std::setw(9) << curr->data.semester << " | "
                   << std::fixed << std::setprecision(2) << curr->data.cgpa << " |\n";
               curr = curr->next;
           }
           std::cout << "-----------------------------------------------------------------------------------------\n";
       }


       void clear() {
           node<T>* curr = H->next;
           while (curr != H) {
               node<T>* temp = curr;
               curr = curr->next;
               delete temp;
           }
           H->next = H;
           n = 0;
       }
   };
}
