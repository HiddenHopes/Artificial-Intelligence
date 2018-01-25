acclen([],Acc,Acc).
acclen([H|T],OldAccLen,Length):-NewAccLen is OldAccLen + 1, acclen(T,NewAccLen,Length).
length(List,Length):-acclen(List,0,Length).