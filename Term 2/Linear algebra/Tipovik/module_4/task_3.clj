(defn vect [a b] [(- (* (a 1) (b 2)) (* (a 2) (b 1)))
                  (- (* (a 2) (b 0)) (* (a 0) (b 2)))
                  (- (* (a 0) (b 1)) (* (a 1) (b 0)))])


(defn abstractOp [f] (fn [& args] (apply mapv f args)))

(defn transpose [m] (apply mapv vector m))

(def v+ (abstractOp +))
(def v- (abstractOp -))
(def v* (abstractOp *))
(def vd (abstractOp /))

(defn scalar [a b] (apply + (v* a b)))

(defn v*s [v s] (mapv (fn [x] (* x s)) v))
(defn m*s [m s] (mapv (fn [x] (v*s x s)) m))
(defn m*v [m v] (mapv (fn [x] (scalar x v)) m))

(defn m*m [m1 m2] (transpose (mapv (fn [v] (m*v m1 v)) (transpose m2))))

(def m+ (abstractOp v+))
(def m- (abstractOp v-))
(def m* (abstractOp v*))
(def md (abstractOp vd))

(def c+ (abstractOp m+))
(def c- (abstractOp m-))
(def c* (abstractOp m*))
(def cd (abstractOp md))


(def x [2, 1, 3, 1, 3])
(def a2 [1, 2, 1, 0, 3])
(def a3 [-1, 0, 2, 3, -1])
(def a1 [0, 1, -1, -1, 1])

(def moduleA1 (Math/sqrt (scalar a1 a1)))

(println
    "var 1\n"
    "module a1 = "
    moduleA1)

(def e1 (v*s a1 (/ 1 moduleA1)))

(println
    "e1 = "
    e1)

(def tempE2 (v- a2 (v*s e1 (scalar a2 e1))))
(def e2 (v*s tempE2 (/ 1 (Math/sqrt (scalar tempE2 tempE2)))))
(println
    "e2 = "
    e2)

(def tempE3 (v- a3 (v*s e1 (scalar a3 e1)) (v*s e2 (scalar a3 e2))))
(def e3 (v*s tempE3 (/ 1 (Math/sqrt (scalar tempE3 tempE3)))))
(println
    "e3 = "
    e3)

(def xl (v+ (v*s e1 (scalar x e1)) (v*s e2 (scalar x e2)) (v*s e3 (scalar x e3))))
(println "xl = " xl)

(def xm (v- x xl))
(println "xm = " xm)

(println
    "var 2\n"
    "x a1 = a (a1, a1) + b (a1, a2) + c (a1, a3)")
(println
    (scalar x a1)
    "="
    (scalar a1 a1)
    "+"
    (scalar a1 a2)
    "+"
    (scalar a1 a3))

(println "x a2 = a (a2, a1) + b (a2, a2) + c (a2, a3)")
(println
    (scalar x a2)
    "="
    (scalar a2 a1)
    "+"
    (scalar a2 a2)
    "+"
    (scalar a2 a3))

(println "x a3 = a (a3, a1) + b (a3, a2) + c (a3, a3)")
(println
    (scalar x a3)
    "="
    (scalar a3 a1)
    "+"
    (scalar a3 a2)
    "+"
    (scalar a3 a3))

(println "Методом Гаусса находите a b c")
(def a -2.2)
(def b 1.6)
(def c -0.4)


(def xl2 (v+ (v*s a1 a) (v*s a2 b) (v*s a3 c)))
(println
    (v*s a1 a)
    "+"
    (v*s a2 b)
    "+"
    (v*s a3 c)
    "="
    xl2)
(def xm2 (v- x xl2))
(println "xm2 = " xm2)

