void swapMove(T& a, T& b)
{
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}

/*The simple swap will hurt performance if type T 
/*is expensive to copy. With move semantics, the implementation
/*can avoid all copying.
/*This is exactly how std::swap() from the Standard Library is 
/*implemented*/