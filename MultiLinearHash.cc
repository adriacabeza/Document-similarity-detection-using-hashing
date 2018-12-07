//Multilinear 
unsigned int hash ( unsigned int ∗ m, unsigned int ∗ p, unsigned int ∗ endp) {
    unsigned int sum = ∗(m++);
    for ( ;p != endp; ++m, ++p)
    sum+= ∗m ∗ ∗p;
    return sum >> 3 2;
}
//Multilinear (2-by-2)
unsigned int hash ( unsigned int ∗ m, unsigned int ∗ p, unsigned int ∗ endp) {
    unsigned int sum = ∗(m++);
    for ( ; p != endp; m += 2 , p += 2 )
        sum += (∗m ∗ ∗p) + ( ∗ (m+1) ∗ ∗(p+1) ) ;
    return sum >> 3 2;
}