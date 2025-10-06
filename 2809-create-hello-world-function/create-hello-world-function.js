/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) //rest operator, except multiple arguments and store in form of array
    {
        return "Hello World"
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */