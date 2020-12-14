Modding for any x64/x86 exe file.<br>
Drag and drop a x64/x86 exe onto the compiled version and it will create a representing modded executable which will query the ExeMods folder in the same directory for dll files and load every single one it finds uppon execution.<br>

It works by pushing a rwx section back into the executables section list then writes the query shell into it, then it redirects the entry point to the section.
