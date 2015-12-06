/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
package org.zeromq.czmq;

public class Zfile implements AutoCloseable{
    static {
        try {
            System.loadLibrary ("czmqjni");
        }
        catch (Exception e) {
            System.exit (-1);
        }
    }
    public long self;
    /*
    If file exists, populates properties. CZMQ supports portable symbolic
    links, which are files with the extension ".ln". A symbolic link is a
    text file containing one line, the filename of a target file. Reading
    data from the symbolic link actually reads from the target file. Path
    may be NULL, in which case it is not used.                           
    */
    native static long __new (String path, String name);
    public Zfile (String path, String name) {
        /*  TODO: if __new fails, self is null...  */
        self = __new (path, name);
    }
    public Zfile (long pointer) {
        self = pointer;
    }
    public Zfile () {
        self = 0;
    }
    /*
    Destroy a file item
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Duplicate a file item, returns a newly constructed item. If the file
    is null, or memory was exhausted, returns null.                     
    */
    native static long __dup (long self);
    public Zfile dup () {
        return new Zfile (__dup (self));
    }
    /*
    Return file name, remove path if provided
    */
    native static String __filename (long self, String path);
    public String filename (String path) {
        return __filename (self, path);
    }
    /*
    Refresh file properties from disk; this is not done automatically   
    on access methods, otherwise it is not possible to compare directory
    snapshots.                                                          
    */
    native static void __restat (long self);
    public void restat () {
        __restat (self);
    }
    /*
    Return when the file was last modified. If you want this to reflect the
    current situation, call zfile_restat before checking this property.    
    */
    native static long __modified (long self);
    public long modified () {
        return __modified (self);
    }
    /*
    Return the last-known size of the file. If you want this to reflect the
    current situation, call zfile_restat before checking this property.    
    */
    native static long __cursize (long self);
    public long cursize () {
        return __cursize (self);
    }
    /*
    Return true if the file is a directory. If you want this to reflect   
    any external changes, call zfile_restat before checking this property.
    */
    native static boolean __isDirectory (long self);
    public boolean isDirectory () {
        return __isDirectory (self);
    }
    /*
    Return true if the file is a regular file. If you want this to reflect
    any external changes, call zfile_restat before checking this property.
    */
    native static boolean __isRegular (long self);
    public boolean isRegular () {
        return __isRegular (self);
    }
    /*
    Return true if the file is readable by this process. If you want this to
    reflect any external changes, call zfile_restat before checking this    
    property.                                                               
    */
    native static boolean __isReadable (long self);
    public boolean isReadable () {
        return __isReadable (self);
    }
    /*
    Return true if the file is writeable by this process. If you want this 
    to reflect any external changes, call zfile_restat before checking this
    property.                                                              
    */
    native static boolean __isWriteable (long self);
    public boolean isWriteable () {
        return __isWriteable (self);
    }
    /*
    Check if file has stopped changing and can be safely processed.
    Updates the file statistics from disk at every call.           
    */
    native static boolean __isStable (long self);
    public boolean isStable () {
        return __isStable (self);
    }
    /*
    Return true if the file was changed on disk since the zfile_t object
    was created, or the last zfile_restat() call made on it.            
    */
    native static boolean __hasChanged (long self);
    public boolean hasChanged () {
        return __hasChanged (self);
    }
    /*
    Remove the file from disk
    */
    native static void __remove (long self);
    public void remove () {
        __remove (self);
    }
    /*
    Open file for reading                             
    Returns 0 if OK, -1 if not found or not accessible
    */
    native static int __input (long self);
    public int input () {
        return __input (self);
    }
    /*
    Open file for writing, creating directory if needed               
    File is created if necessary; chunks can be written to file at any
    location. Returns 0 if OK, -1 if error.                           
    */
    native static int __output (long self);
    public int output () {
        return __output (self);
    }
    /*
    Returns true if zfile_read() just read the last chunk in the file.
    */
    native static boolean __eof (long self);
    public boolean eof () {
        return __eof (self);
    }
    /*
    Read next line of text from file. Returns a pointer to the text line,
    or NULL if there was nothing more to read from the file.             
    */
    native static String __readln (long self);
    public String readln () {
        return __readln (self);
    }
    /*
    Close file, if open
    */
    native static void __close (long self);
    public void Close () {
        __close (self);
    }
    /*
    Calculate SHA1 digest for file, using zdigest class.
    */
    native static String __digest (long self);
    public String digest () {
        return __digest (self);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public void test (boolean verbose) {
        __test (verbose);
    }
}
