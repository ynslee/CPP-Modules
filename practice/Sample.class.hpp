
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

/**
 * Class Sample -> class(keyword) Sample(identifier)
 * declare constructor : Sample(void);
 * ~Sample is desconstructor.
 * Constuctor of instances, descontructor of instances
 */
// class Sample {

// public:

// 	int	foo;

// 	Sample(void);
// 	~Sample(void);

// 	void bar(void);
// };

// #endif


/**
 * @brief const keyword after argument, you are telling the compiler
 * this will not alter the constance 
 */
class Sample {

public:

	float const	const_value;
	int			qd;

	Sample( float const f );
	~Sample(void);

	void bar(void) const;
};

#endif