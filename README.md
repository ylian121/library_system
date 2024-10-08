# CS100 Library system project
 > Authors: [Aaron Hernandez-Sledge](https://github.com/AaronSledge) [Haard Shah](https://github.com/haasha600) [Alan Diaz](https://github.com/alandiazv) [Yongyan Liang](https://github.comylian121)


## Why are our project is important

 > We chose a libarary system because the description sounds interesting. Also it is something that is applicable in real world. Along with this, this project is important as it provides a solution to sorting a large set of data. It provides conveince, efficency, and a way for users to discover new books. Being able to sort a large set of books is a challenge on its own, providng us an opportunity to learn how to handle a big project of this magntiude.
 > For this project we only need to use c++ for our language


## INPUT/OUTPUT
 > For our input, users will be able to enter in their email and password to sign in and login. After that enter users can enter and look through books by their titles and genres. They would also be able pick the books you want to borrow.
> In terms of output, users will be able to see the books that is in our library. Users will also be able to know whether a book is avivilable or not. They will also be able to see any books recommended to them 

## Our features we want are
   > * Users being able sign in or log into account(this information will be stored in a txt file)
   > * Users should be able to see all books that are avilable
   > * Users are able to filter out books based on said genre or combine genres
   > * Users should be to see their reading history
   > * Adminstrators should be able to add, edit, or delete books from the library
   > * Users should be able to see account debt
   > * There should be book recommendation feature based off of user reading history     

 > ## Phase II
## User Interface Specification

### Navigation Diagram
> 
><img width="849" alt="Screen Shot 2024-05-06 at 7 06 48 PM" src="https://github.com/cs100/final-project-ahern561-hshah050-adiaz205-ylian121/assets/165940838/54027d57-98fc-4261-ba1c-e4d0568952b5">

>
> 
>
> Navigation Diagram Description: The starting page is the homepage for the library system. On the homepage, the user can get to know a bit about the library system. If they want to access more actions, they would need to have an account and login into their account. There are two different login options because the library system is for users and admins and they have different access to the library system. When the admin logins, they have access to editing the library system because they are able to change, edit, add, and remove books from the library system. Then they can see the new updated library system. The admin can also manage and oversee account debts so they can edit and make any actions neccessary to change and add account debts. The user has much more features so when they login, they will go into their user account. From their user account, they can go into their account debt to see if they have any payments they need to make. From the account debt, they can go into the payment page to make their payment. They can also go into the book library to see all the available books that they can borrow and check out. From the book library, they can pick and choose different genres and the book library will be updated showing only the genres the user wants to see. They can also go into the borrowing book page from the book library when they have picked out all the books they want to borrow. From their user account, they can go into their reading history to look at all the books that they have read in the past. From the history page, they can go into a book recommendation page to see what books are recommended to them based on their past readings. From here, they can go to check out books that they want to read from their recommendations. From the check out books page, after they have successfully checked out the books, they will go back to their user account to see if the transaction went through.

>
> ### Screen Layouts
>Our screens is just going to consists of the terminal output. The first thing user see is a prompt to sign in. We would want to ask if a user is a consumer or admin due to different features being aviliable. If player picked user it will go to the home menu which welcomes the user. Then they will have a variety of options to choose from seeing book history, returning books, and seeing the catalog. The admin home screen differs because they will able to directly add, remove, or edit books from the library. When users pick see catalog, they will be able to see the entire list of book we hold in the collection. As with book history, a specfic user's reading history will all be displayed to the terminal.
>
>![screen diagram](https://github.com/cs100/final-project-ahern561-hshah050-adiaz205-ylian121/assets/120629557/f450418a-ce2f-493a-b464-89a483c4ad83)



## Class Diagram
![UML_Diagram](https://github.com/cs100/final-project-ahern561-hshah050-adiaz205-ylian121/assets/67347173/fe4bdd98-6a3b-4617-8213-c40ed53ebaf9)

 > ## Phase III

>Our classes all follow the SOLID principles. Every single class has exactly one role: to represent the object and manipulate its data. The single responsibilty principle made our code better because each class will only have one role. This ensures that a class is not trying to do a lot at the same time. The classes only have one role and this ensures that our classes are short and simple to understand. Every single class won't be too long and complicated because it only has one job. SRP made our code cleaner and shorter to read. All of our objects are open to extension but closed to modification once implemented. The open close principle made our code better because it won't cause any errors when trying to extend what is inherited. It made our code better because we are able to add new features and new functions in our project without breaking anything. This solide principle saves us a lot of issues that will happen otherwise. OCP made our code better because it gives less error if our code is only open for extension without changing what is already done. In all instances of inheritance, all subclasses can substitute and function as an instance of the parent class. The Liskov substituion principle allows the subclasses to replace objects from the parent classes. This ensures that it won't affect what is already done with our parent class. It ensures that our subclasses that inherit from the parent class can do their own thing when replacing certain objects from the parent class. LSP made our code better with good reusability so our subclasses can replace the object from the parent class anytime. Our class design also doesn't allow for interfaces that can violate the ISP or DIP. The dependency inversion principle ensures that the high level modules won't depend on low level modules. This makes it so it is easy to extend our code without causing errors. DIP made our code better by allowing for extendability and flexibility. The interface segregation principle ensures that clients that don't use something won't have to depend on it. In order to ensure that clients don't have to depend of what they don't need to use, we have to keep the interface specific. It makes sure that our interface is not too long. ISP made our code better by keeping interfaces short and simple and not too complicated.
 
 > ## Final deliverable
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 
 ## Screenshots
 > Screenshots of the input/output after running your application

 ## Installation/Usage
> Instruction of running application:
> 1. run the project/program
> 2. you will see the terminal output asking for your input to sign in or log in
> 3. input your option
> 4. you will then be brought to the next terminal output asking for your role
> 5. log in or sign up
> 6. after logging into your account, you are open to a lot of options to pick from
> 7. there are actions such as add book, remove book, add genre, remove genre, etc
> 8. make your choice to nagivate our library system
 ## Testing
> Our project is tested and validated with unit tests for each class and each function within each class. Our unit tests are testing to see if each function work as intended with expecting certain values, expecting true or false and with the other different types of expects for unit tests. Most of the unit tests are passing to ensure the correctness of each function and that is how our project is tested and validated.
 
Collapse












