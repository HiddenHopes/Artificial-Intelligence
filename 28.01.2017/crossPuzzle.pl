word(astante,  a,s,t,a,n,t,e).
word(astoria,  a,s,t,o,r,i,a).
word(baratto,  b,a,r,a,t,t,o).
word(cobalto,  c,o,b,a,l,t,o).
word(pistola,  p,i,s,t,o,l,a).
word(statale,  s,t,a,t,a,l,e).

crossword(Vleft,Vmid,Vright,Htop,Hmid,Hbottom):-
                    word(Vleft, V11, H1V1, V13, H2V1, V15, H3V1, V17),
                    word(Vmid, V21, H1V2, V23, H2V2, V25, H3V2, V27),
                    word(Vright, V31, H1V3, V33, H2V3, V35, H3V3, V37),
                    word(Htop, H11, H1V1, H13, H1V2, H15, H1V3, H17),
                    word(Hmid, H21, H2V1, H23, H2V2, H25, H2V3, H27),
                    word(Hbottom, H31, H3V1, H33, H3V2, H35, H3V3, H37).
