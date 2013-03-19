module main where
import system.environment

main :: io ()
main = do args <- getargs
          putstrln ("hello, " ++ args !! 0)
