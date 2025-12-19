This sample document showcase the output log for each function in the system. Record from program startup. Cases may uses different pre-filled data, please see the description in each case block.

**Table of Contents**:

[[_TOC_]]

# "Login" Menu

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

## If invalid option number is given, give a warning and continue.

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 4
Invalid choice! Please enter a number between 1 and 3.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

## Exit

Exit the program.

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 3
Byebye!
Press any key to continue...
```

## Login - When there is no account in this program

When there is no account in this program, if a user try to login:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Tom
and password: 123
No user in this system, please register one.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

## Register

If account name not used but two passwords different, give a warning.

account: Cindy  
password: 123456  
confirm password: 654321

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: Cindy
Enter password: 123456
Confirm password: 654321
Passwords do not match. Registration failed.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### If account name not used and two passwords are the same, register successfully.

account: Cindy  
password: 4567A8  
confirm password: 4567A8

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: Cindy
Enter password: 4567A8
Confirm password: 4567A8
Registration successful! You can now login.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### If account name used, give a warning.

Account "Cindy" already exists.

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: Cindy
Account name already exists.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### Register more accounts

account info:  
|  name  | password |
| ------ | ------   |
| Emily  | e9M2xQ   |
| James  | j8#Kp3   |
| Sophia | s5Rf@v   |

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: Emily
Enter password: e9M2xQ
Confirm password: e9M2xQ
Registration successful! You can now login.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: James
Enter password: j8#Kp3
Confirm password: j8#Kp3
Registration successful! You can now login.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 2
Enter account name: Sophia
Enter password: s5Rf@v
Confirm password: s5Rf@v
Registration successful! You can now login.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

## Manually combine all the .txt files generated until this stage into stage1.zip file.

** Manually combine all the .txt files generated until this stage into stage1.zip file. ** 

## Login - When there are accounts in this program

### If the input account not registered, give a warning.

account: Tom  
password: 123

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Tom
and password: 123
Warning! Account name not found.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### If the input account exists but password incorrect, give a warning.

account: Cindy  
password: 123456

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 123456
Warning! Incorrect password.
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### If the input account exists and password correct, login successfully and "Main Service" menu shown.

account: Cindy  
password: 4567A8

In "Main Service" menu, user is able to go back to "Login" menu.

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

# Main Service - Manage Friends

## Add friends (Login as "Cindy")

### Add Cindy herself, give a warning.

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Cindy
You cannot send a friend request to yourself.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Add an account that not exists, give a warning

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Apple
Account Apple does not exist.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Add an existant account for the first time

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Emily
Friend request sent to Emily.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Add an existant account for the second time

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Emily
Friend request to Emily is already pending.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Add more than one accounts (self, not exists, requested) at the same time

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Cindy Apple Emily
You cannot send a friend request to yourself.
Account Apple does not exist.
Friend request to Emily is already pending.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Add more than one accounts (all kinds) at the same time

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Cindy James Apple Emily Sophia
You cannot send a friend request to yourself.
Friend request sent to James.
Account Apple does not exist.
Friend request to Emily is already pending.
Friend request sent to Sophia.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

## Add friends (Switch user from "Cindy" to "Emily")

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 
```

### Add an account that has sent request to the current user

Current user Emily try to add Cindy, but Cindy has requested to add Emily before

```
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Cindy
Cindy has sent friend request to you.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

### Switch to different accounts and add friends

Current user: Emily  
1. Enter "Accept friends", there will be "Cindy" in the pending friend requests list
2. Go back to "Add friends" to add "James" and "Sophia"
3. Go back to "Login"

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
Pending friend requests for Emily:
1. Cindy
2. All
3. Back
Enter indices (space separated), press Enter to finish: 3
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): James Sophia
Friend request sent to James.
Friend request sent to Sophia.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "James", add "Sophia":

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 1
Enter usernames to add (in one line separated by space): Sophia
Friend request sent to Sophia.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 
```

## Delete/Show current friends - when the user have no friends

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

## Accept friends & Show current friends

Current account: James

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
Pending friend requests for James:
1. Cindy
2. Emily
3. All
4. Back
Enter indices (space separated), press Enter to finish: 2
Friend requests updated for Emily.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Emily
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5):2
Pending friend requests for James:
1. Cindy
2. All
3. Back
Enter indices (space separated), press Enter to finish: 1
Friend requests updated for Cindy.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Cindy
2. Emily
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5):2
No pending friend requests for James.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Sophia", accept all friends and show current friends:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Sophia
and password: s5Rf@v
Login successful. Welcome Sophia!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
Pending friend requests for Sophia:
1. Cindy
2. Emily
3. James
4. All
5. Back
Enter indices (space separated), press Enter to finish: 1 2
Friend requests updated for Cindy.
Friend requests updated for Emily.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Cindy
2. Emily
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
Pending friend requests for Sophia:
1. James
2. All
3. Back
Enter indices (space separated), press Enter to finish: 2
Friend requests updated for all.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Emily", show current friends, accept all friends and show current friends again:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. James
2. Sophia
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
Pending friend requests for Emily:
1. Cindy
2. All
3. Back
Enter indices (space separated), press Enter to finish: 2
Friend requests updated for all.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Cindy
2. James
3. Sophia
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Cindy", accept friends and show current friends:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 2
No pending friend requests for Cindy.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Emily
2. James
3. Sophia
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

## Manually combine all the .txt files generated until this stage into stage2.zip file.

** Manually combine all the .txt files generated until this stage into stage2.zip file. **

## Delete friends - When current friend list not empty

Current account: Cindy

Delete one friend:

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Emily
2. James
3. Sophia
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
Your friends:
1. Emily
2. James
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 3
Deleting Sophia...
Friend list updated.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Sophia", check the current friends of Sophia:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Sophia
and password: s5Rf@v
Login successful. Welcome Sophia!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
Your friends:
1. Emily
2. James
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 
```

Delete multiple friends:

```
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
Your friends:
1. Emily
2. James
3. All
4. Back
Enter friend numbers (separated by space), press Enter to finish: 2 1
Deleting James...
Deleting Emily...
Friend list updated.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "James" and delete all friends:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
Your friends:
1. Cindy
2. Emily
3. All
4. Back
Enter friend numbers (separated by space), press Enter to finish: 3
Deleting all...
Friend list updated.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Emily" and delete all friends:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
Your friends:
1. Cindy
2. All
3. Back
Enter friend numbers (separated by space), press Enter to finish: 2
Deleting all...
Friend list updated.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

Login as "Cindy", delete all friends:

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 1
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 3
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 4
You have no friends.
==================== Manage Friends ====================
1. Add friends
2. Accept friends
3. Delete friends
4. Show current friends
5. Back
========================================================
Choose an option (1-5): 5
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 3
Byebye!
Press any key to continue...
```

# Main Service - Manage Messages
Before testing "Manage Messages", we need to repeat the previous operations before ["Delete friends - When current friend list not empty"](#delete-friends-when-current-friend-list-not-empty). That is, Cindy, Emily, James and Sophia are friends of each other.

## Read/Delete messages - when the user have no messages

Login as "James":

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 
```

## Send/Read messages

### Message sending between two friends (James and Cindy)

1. James send a message to Cindy:

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Hi Cindy, are we still meeting for lunch tomorrow?
Your friends:
1. Cindy
2. Emily
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 1
Message sent to Cindy
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

2. Cindy read messages from James

Login as "Cindy":

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 10:54:31] From: James
Hi Cindy, are we still meeting for lunch tomorrow?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
Found no messages.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 10:54:31] From: James
Hi Cindy, are we still meeting for lunch tomorrow?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 
```

3. Cindy send a message to James

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Yes, 12:30 at the usual place?
Your friends:
1. Emily
2. James
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 2
Message sent to James
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

4. James read messages from Cindy

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 11:16:11] From: Cindy
Yes, 12:30 at the usual place?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3):
```

### Send a message to selected friends

1. Emily send a message to Cindy and Sophia

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Emergency meeting in 10 minutes!
Your friends:
1. Cindy
2. James
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 1 3
Message sent to Cindy
Message sent to Sophia
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3):
```

2. Cindy reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
Found no messages.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 10:54:31] From: James
Hi Cindy, are we still meeting for lunch tomorrow?
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

3. Sophia reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Sophia
and password: s5Rf@v
Login successful. Welcome Sophia!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
Found no messages.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### Send a message to all friends

1. Emily send a message to all friends

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Emergency meeting in 5 minutes!
Your friends:
1. Cindy
2. James
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 4
Message sent to All==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

2. Cindy reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Cindy
and password: 4567A8
Login successful. Welcome Cindy!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 10:54:31] From: James
Hi Cindy, are we still meeting for lunch tomorrow?
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

3. James reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 11:16:11] From: Cindy
Yes, 12:30 at the usual place?
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3):
```

4. Sophia reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Sophia
and password: s5Rf@v
Login successful. Welcome Sophia!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 
```

### Send a message from different users to their friends

1. Sophia continue to send a message to Emily

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Running late, save me a seat
Your friends:
1. Cindy
2. Emily
3. James
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 2
Message sent to Emily
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

2. James sends a message to Sophia

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 1
Enter message (max 255 chars), press Enter to finish: Can you review my presentation?
Your friends:
1. Cindy
2. Emily
3. Sophia
4. All
5. Back
Enter friend numbers (separated by space), press Enter to finish: 3
Message sent to Sophia
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

3. Emily reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Emily
and password: e9M2xQ
Login successful. Welcome Emily!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:51:38] From: Sophia
Running late, save me a seat
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 12:51:38] From: Sophia
Running late, save me a seat
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

4. Sophia reads messages

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: Sophia
and password: s5Rf@v
Login successful. Welcome Sophia!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 2
[2025-11-21 12:55:12] From: James
Can you review my presentation?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 12:05:38] From: Emily
Emergency meeting in 10 minutes!
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
[2025-11-21 12:55:12] From: James
Can you review my presentation?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 
```

## Manually combine all the .txt files generated until this stage into stage3.zip file.

** Manually combine all the .txt files generated until this stage into stage3.zip file. **

## Delete messages

### Delete messages during a no message period

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
Enter start date (dd/mm/yyyy): 20/11/2025
Enter end date (dd/mm/yyyy): 20/11/2025
Enter account name (or 'all'): Emily
Removed 0 message(s) from Emily in period 20/11/2025 - 20/11/2025.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
Enter start date (dd/mm/yyyy): 20/11/2024
Enter end date (dd/mm/yyyy): 20/12/2024
Enter account name (or 'all'): all
Removed 0 message(s) from all in period 20/11/2024 - 20/12/2024.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 
```

### Delete messages from a not existant friend

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
Enter start date (dd/mm/yyyy): 21/11/2025
Enter end date (dd/mm/yyyy): 21/11/2025
Enter account name (or 'all'): Apple
Removed 0 message(s) from Apple in period 21/11/2025 - 21/11/2025.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4):  
```

### Delete messages of a valid friend during a valid period

```
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
Enter start date (dd/mm/yyyy): 21/11/2025
Enter end date (dd/mm/yyyy): 21/11/2025
Enter account name (or 'all'): Emily
Removed 2 message(s) from Emily in period 21/11/2025 - 21/11/2025.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 12:55:12] From: James
Can you review my presentation?
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 
```

### Delete all messages

Login as "James":

```
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 1
Please input your account name: James
and password: j8#Kp3
Login successful. Welcome James!
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 2
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
1. Read all messages
2. Read unread messages only
3. Back
Choose an option: 1
[2025-11-21 11:16:11] From: Cindy
Yes, 12:30 at the usual place?
[2025-11-21 12:41:56] From: Emily
Emergency meeting in 5 minutes!
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
Enter start date (dd/mm/yyyy): 21/11/2025
Enter end date (dd/mm/yyyy): 21/11/2025
Enter account name (or 'all'): all
Removed 2 message(s) from all in period 21/11/2025 - 21/11/2025.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 2
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 3
No messages found.
==================== Manage Messages ====================
1. Send a message
2. Read messages
3. Delete messages
4. Back
=========================================================
Choose an option (1-4): 4
==================== Main Service ====================
1. Manage friends
2. Manage messages
3. Back
======================================================
Choose an option (1-3): 3
==================== Login ====================
1. Login
2. Register (If you do not have an account)
3. Exit
===============================================
Choose an option (1-3): 3
Byebye!
Press any key to continue...
```
