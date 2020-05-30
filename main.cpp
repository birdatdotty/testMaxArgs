/*
 * довольно тупо создаю тестовый test.c, собираю и выполняю (gcc test.c && ./a.out),
 * чтобы проверить максимальное число параметров,
 * передоваемоя в функцию.
 * на 246 687 - нормально собирается и при это нормально выполняется (естественно идет переполнение int)
 * на 246 688 - не собирается (gcc: internal compiler error: Ошибка сегментирования signal terminated program cc1)
 */

#include <QCoreApplication>
#include <QFile>

QString body() {
//    const int max = 999999;
//    const int max = 99999;
    int max;
    max = 246687; // 246 687 -- компилится
//  max = 246688; // 246 688 -- вызывает ошибку

    QString ret;
    ret += "#include <stdio.h>\n\n";

    ret += "int sum(int n0";
    for (int i = 1; i < max; i++)
        ret += ", int n" + QString::number(i);
    ret += ") {\n  int s = n0";

    for (int i = 1; i < max; i++) {
        ret += " + n" + QString::number(i);
    }

    ret += ";\n\n  return s;\n}\n\n";

    ret += "int main() {\n";
    for (int i = 0; i < max; i++)
        ret += "  int n" + QString::number(i) + " = " + QString::number(i) + ";\n";

    ret += "\n  printf(\"%i\\n\", sum(n0";
    for (int i = 1; i < max; i++)
        ret += ", n" + QString::number(i);
//            1,2,3,5
    ret += "));\n\n";
    ret += "  return 0;\n}\n\n";

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile c("test.c");
    if (c.open(QIODevice::WriteOnly)) {
        c.write(body().toUtf8());
    }

    c.close();

    return EXIT_SUCCESS;
}
