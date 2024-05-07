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
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

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
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
Collapse












Hello, team!

Let’s use this space to…

Status update:











