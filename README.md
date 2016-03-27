<div>
<h2> SPbAU llvm project </h2>
<p> Building the project: </p>
<pre>
$ mkdir llvm_project
$ git clone https://github.com/Karma-Police/SPbAU_llvm-project.git ./llvm_project
$ cd ./llvm_project
$ mkdir build
$ cd ./build
$ cmake ../passes/
$ make 
</pre>
<p> 
If llvm or llvm headers not found check this: http://llvm.org/docs/CMake.html#embedding-llvm-in-your-project
</p>

</div>
