# Write your MySQL query statement below
Select U.Name,SUM(T.amount) balance from Users U
join Transactions T on U.account = T.account
group by T.account
having balance > 10000