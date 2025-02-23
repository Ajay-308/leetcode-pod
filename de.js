//data encapsulation in js using closure
// clousre is a function that has access to the outer function scope even after the outer function has returened

function counter() {
  let count = 5;

  return {
    increment: function () {
      count++;
      console.log(count);
    },
    decrement: function () {
      count--;
      console.log(count);
    },
  };
}

const myCounter = counter();
myCounter.increment(); // 1
myCounter.increment(); // 2
myCounter.decrement(); // 1
console.log(myCounter.count); // Undefined (cannot access directly)
