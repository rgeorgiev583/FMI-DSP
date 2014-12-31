%s/friend \([A-Za-z]\+\)& operator>>(\([A-Za-z]\+\)& ns, \(.\+\))/\1\& operator>>(\3)/g
%s/return ns/return *this/g
%s/ns.n/n/g

