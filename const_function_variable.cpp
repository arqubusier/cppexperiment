// This example shows that const objects may be placed on the stack (compile with -O0) 
int foo() {
  //int var{1};
  int const var{1}; // same result as without const 
  return var;
}

int main() {
  return foo();
}