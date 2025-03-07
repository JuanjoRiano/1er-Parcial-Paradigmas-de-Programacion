import Data.List (sortBy)
import Data.Ord (comparing)
import Control.Arrow (Arrow(first))

type Estudiante = (String, Float)

bubbleSortDescending :: [Estudiante] -> [Estudiante]
bubbleSortDescending = sortBy (comparing (negate. snd) <> comparing fst)

main :: IO()
main = do
    let estudiantes = [("Ana", 85), ("Luis", 90), ("Carlos", 85), ("Sofia", 92), ("Maria", 90)]
    print( bubbleSortDescending estudiantes)


