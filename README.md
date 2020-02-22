# NJ-NS-Project3
Project 3, Nolan Jimmo and Noah Stracqualursi 

The outline of our class hierarchy goes like this:
Bank -> Branch     Accounts(Person)
The branch inherits the Bank class, while the accounts is an unrelated class with a component class being a person.
We decided to do this because it does make a lot of sense... a branch would naturally inherit it's parent bank's qualities
and extend that with a branch manager and list of accounts. Although there are accounts within the bank, technically they
are unrelated because they only reside within a branch in a list. A branch manages a list of accounts. Then, a person is
a component of each account because that is more than half of the account... the account holder. So an account has a Person
field that describes who the account holder is and some different things about them. It may be a slight stretch to see how
an account is independent of a branch, but in reality they don't have anything in common... as I said before, the branch 
really just manages the accounts, the accounts don't take anything or really interact with the branch at all, other than
storing physical money there (in real life).

Other than that, the interface of the bank should work as a normal bank does. Once you pick a branch, you can't change 
it because no one really has two accounts in the same bank in two different branches. From inside the branch you can do
everything that you need... create accounts, deposit money, etc. as you should be able to.
