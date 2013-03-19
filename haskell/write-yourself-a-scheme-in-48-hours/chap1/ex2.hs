module Main where
import System.Environment

main :: IO ()
main = do args <- getArgs
          a <- return (read (args !! 0))
          b <- return (read (args !! 1))
          putStrLn (show (a + b))
