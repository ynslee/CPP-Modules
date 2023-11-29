
#ifndef SAMPLE3_CLASS_H
# define SAMPLE3_CLASS_H

/**
 * Class Sample -> class(keyword) Sample(identifier)
 * declare constructor : Sample(void);
 * ~Sample is desconstructor.
 * Constuctor of instances, descontructor of instances
 */
class Sample3{

public:

	Sample3(int v);
	~Sample3(void);

	int	getfoo(void) const;
	int	compare (Sample3 *other) const;

private:

	int _foo;

};

#endif